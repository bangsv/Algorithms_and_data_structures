#include <iostream>
#include "Stack_Header.h"

using namespace std;

void InitStack(Stack* s, unsigned Size) { // Yes
	s->size_Stack = 0;
	s->Start_Stack = NULL;
	s->ptr_Stack = s->Start_Stack;
	s = (Stack*)malloc(sizeof(Stack));
}

void PutStack(Stack* s, BaseType_Stack E) { // Yes
	ptrel_Stack node = (ptrel_Stack)new ptrel_Stack;
	
	node->data_Stack = E;
	node->next_Stack = s->ptr_Stack;

	s->ptr_Stack = node;
	s->size_Stack += 1;

}

unsigned GetStack(Stack* s) { // Yes 
	s->size_Stack -= 1;
	ptrel_Stack node = s->ptr_Stack;
	unsigned E = node->data_Stack;
	node = node->next_Stack;
	s->ptr_Stack = node;
	return E;
}

bool EmptyStack(Stack* s) { // Yes
	return s->size_Stack == 0 ? false : true;
}

void ReadStack(Stack* s) { // Yes
	if (s->size_Stack == 0) {
		cout << endl << "Stack empty!" << endl;
	}
	else 	if (s->size_Stack > 0) {
		cout << endl << s->ptr_Stack->data_Stack << endl;
	}
}

void DoneStack(Stack* s) { // Yes
	delete s;
}
