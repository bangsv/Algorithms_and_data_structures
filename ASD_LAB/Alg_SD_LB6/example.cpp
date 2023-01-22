#include <iostream>
#include <thread>
#include "Fifo_Header.h"
#include "Stack_Header.h"
#include "Task_Header.h"

using namespace std;

void Input_F1_in_P1(Fifo* F1, bool& checkP1);
void Input_F2_in_P2(Fifo* F2, bool& checkP2);
void Input_F3_in_P1_or_P2(Fifo* F1, Fifo* F2, Fifo* F3, bool& checkP1, bool& checkP2);
void Input_F1_in_P2(Fifo* F1, Fifo* F2, bool checkP1, bool& checkP2, bool& checkP3);
void Input_Stack_F1(Stack* stack, Fifo* F1, Fifo* F2, bool checkP1, bool checkP2);
void Input_F2_in_P1(Fifo* F1, Fifo* F2, bool& checkP1, bool checkP2);
void Input_Stack_F2(Stack* stack, Fifo* F1, Fifo* F2, bool checkP1, bool checkP2);
void OutPut_Stack(Stack* stack, Fifo* F1, Fifo* F2, bool& checkP1, bool& checkP2);

bool checkP1 = true;
bool checkP2 = true;
bool checkP3 = true;

int main() {

	srand(time(NULL));

	// Инициализация Стека и очереди.
	Fifo* F1 = new Fifo[sizeof(Fifo)];
	Fifo* F2 = new Fifo[sizeof(Fifo)];
	Fifo* F3 = new Fifo[sizeof(Fifo)];

	Stack* stack = new Stack[sizeof(Stack)];
	TInquiry* objective = new TInquiry[sizeof(TInquiry)];

	InitFifo(F1);
	InitFifo(F2);
	InitFifo(F3);

	InitStack(stack, 100);

	for (int i = 0; i < 7; i++) {
		//Генерируем задачи и распределяем их по очередям;
		Task_Generator(objective);
		objective->Time = (unsigned)i + 1;
		cout << "Type: " << objective->T <<" Time: "<<objective->Time  << " Name: " << objective->Name << endl;


		if (objective->T == "T1")
			PutFifo(F1, objective->Time);

		if (objective->T == "T2")
			PutFifo(F2, objective->Time);

		if (objective->T == "T3")
			PutFifo(F3, objective->Time);

	}
	cout << endl;
	for (int i = 0; i < 10; i++) {


		thread F1_P1(Input_F1_in_P1, ref(F1), ref(checkP1));
		thread F2_P2(Input_F2_in_P2, ref(F2), ref(checkP2));
		thread F3_int_P1_or_P2(Input_F3_in_P1_or_P2, ref(F1), ref(F2), ref(F3), ref(checkP1), ref(checkP2));
		thread F1_int_P2(Input_F1_in_P2, ref(F1), ref(F2), ref(checkP1), ref(checkP2), ref(checkP3));
		thread Stack_F1(Input_Stack_F1, ref(stack), ref(F1), ref(F2), ref(checkP1), ref(checkP2));
		thread F2_in_P1(Input_F2_in_P1, ref(F1), ref(F2), ref(checkP1), ref(checkP2));
		thread Stack_F2(Input_Stack_F2, ref(stack), ref(F1), ref(F2), ref(checkP1), ref(checkP2));
		thread OPUT_STACK(OutPut_Stack, ref(stack), ref(F1), ref(F2), ref(checkP1), ref(checkP2));
		F1_P1.join();
		F2_P2.join();
		F3_int_P1_or_P2.join();
		F1_int_P2.join();
		Stack_F1.join();
		F2_in_P1.join();
		Stack_F2.join();
		OPUT_STACK.join();

	}

}

void Input_F1_in_P1(Fifo* F1, bool& checkP1) {
	if (EmptyFifo(F1) == true && checkP1 == true) { // . Если очередь F1 не пуста и процессор P1 свободен, 
		checkP1 = false;					        //то задача из очереди F1 поступает на обработку в процессор P1. 
		cout << "Working P1 for F1 " << "\t" << F1->ptr_Fifo->data << endl;
		checkP1 = P1(GetFifo(F1));
	}
}

void Input_F2_in_P2(Fifo* F2, bool& checkP2) {
	if (EmptyFifo(F2) == true && checkP2 == true) { //Если очередь F2 не пуста и процессор P2 свободен, 
		checkP2 = false;					       // то задача из очереди F2 поступает на обработку в процессор P2.
		cout << "Working P2 for F2 " << "\t" << F2->ptr_Fifo->data << endl;
		checkP2 = P2(GetFifo(F2));
	}
}

void Input_F3_in_P1_or_P2(Fifo* F1, Fifo* F2, Fifo* F3, bool& checkP1, bool& checkP2) {
	if ((EmptyFifo(F3) == true && checkP1 == true && EmptyFifo(F1) == false) || //Если процессор Р1 обрабатывает задачу типа Т3,
		(EmptyFifo(F3) == true && checkP2 == true && EmptyFifo(F2) == false)) { //Если процессор Р2 обрабатывает задачу типа Т3,
		if (checkP1 == true) {
			checkP1 = false;
			checkP3 = false;
			cout << "Working P1 for F3: " << "\t" << F3->ptr_Fifo->data << endl;
			checkP1 = P1(GetFifo(F3)); //Если процессор Р1 обрабатывает задачу типа Т3,
			checkP3 = checkP1;
		}
		else if (checkP2 == true && EmptyFifo(F3) == true && checkP3 == true) {
			checkP2 = false;
			cout << "Working P2 for F3: " << "\t" << F3->ptr_Fifo->data << endl;
			checkP2 = P2(GetFifo(F3)); //Если процессор Р2 обрабатывает задачу типа Т3,
		}
	}
}

void Input_F1_in_P2(Fifo* F1, Fifo* F2, bool checkP1, bool& checkP2, bool& checkP3) {
	if (EmptyFifo(F2) == false && checkP2 == true && checkP1 == false && checkP3 == false) { //Если процессор Р1 обрабатывает задачу типа Т3,
		checkP2 = false;																	 // а процессор Р2 свободен и очередь F2 пуста, 														 //т о задача из процессора Р1 поступает в процессор Р2
		cout << "Working P2 for F1: " << "\t" << F1->ptr_Fifo->data << endl;
		checkP2 = P2(GetFifo(F1));
	}
}

void Input_Stack_F1(Stack* stack, Fifo* F1, Fifo* F2, bool checkP1, bool checkP2) {
	if (EmptyFifo(F2) == true && checkP2 == true && checkP1 == false) { //если же процессор Р2 занят или очередь F2 не пуста,  
		cout << "Stack fill F1: " << "\t" << F1->ptr_Fifo->data << endl;
		PutStack(stack, GetFifo(F1));									  //то задача из процессора Р1 помещается в стек.
	}
}

void Input_F2_in_P1(Fifo* F1, Fifo* F2, bool& checkP1, bool checkP2) {
	if (EmptyFifo(F1) == false && checkP1 == true && EmptyFifo(F2) == true) { // Процессор Р1 свободен и очередь F1 пуста, 
		checkP1 = false;													 // то задача из процессора Р2 поступает в  											// процессор Р1, а задача из очереди F2 — в процессор Р2, 
		cout << "Working P1 for F2 " << "\t" << F2->ptr_Fifo->data << endl;
		checkP1 = P1(GetFifo(F2));
	}
}

void Input_Stack_F2(Stack* stack, Fifo* F1, Fifo* F2, bool checkP1, bool checkP2) {
	if ((EmptyFifo(F2) == true || checkP2 == false)) { //если же процессор Р2 занят или очередь F2 не пуста,
		cout << "Stack fill F2 " << "\t\t" << F2->ptr_Fifo->data << endl;
		PutStack(stack, GetFifo(F2));										//то задача из процессора Р1 помещается в стек. 
	}
}

void OutPut_Stack(Stack* stack, Fifo* F1, Fifo* F2, bool& checkP1, bool& checkP2) {
	if ((EmptyStack(stack) == true && checkP1 == true && EmptyFifo(F1) == false) || //Задача из стека поступает на обработку в свободный 
		(EmptyStack(stack) == true && checkP2 == true && EmptyFifo(F2) == false)) { //процессор Р1, если очередь F1 пуста, или в
		if (checkP1 == true) {														// свободный процессор Р2, если очередь F2 пуста.
			checkP1 = false;
			cout << "Working P1 for stack " << "\t" << stack->ptr_Stack->data_Stack << endl;
			checkP1 = P1(GetStack(stack));
		}
		if (checkP2 == true && EmptyStack(stack) == true) {
			checkP2 = false;
			cout << "Working P2 for stack " << "\t" << stack->ptr_Stack->data_Stack << endl;
			checkP2 = P2(GetStack(stack));
		}
	}
}
