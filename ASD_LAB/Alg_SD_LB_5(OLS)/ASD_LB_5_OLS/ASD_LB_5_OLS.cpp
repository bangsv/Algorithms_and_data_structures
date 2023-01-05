#include <iostream>

using namespace std;

#if !defined(__LIST1_H)
const int ListOk = 0;
const int ListNotMem = 1;
const int ListUnder = 2;
const int ListEnd = 3;
typedef int* BaseType;
typedef struct element* ptrel;

typedef struct element {
	BaseType data;
	ptrel next;
};

typedef struct List {
	ptrel Start; // Самый первый элемент 
	ptrel End; // Последний элемент
	ptrel ptr; //Конец списка tail 
	unsigned int size;
};

short ListError;

void InitList(List* L);  //Yes
void PutList(List* L, BaseType E); //Yes
void GetList(List* L, BaseType* E); //Yes
void ReadList(List* L); //Yes
int FullList(List* L); //Yes
int EndList(List* L); //Yes

int  Count(List* L); // Yes
void BeginPtr(List* L); // Yes
void EndPtr(List* L); // Yes
void MovePtr(List* L); //Yes
void MoveTo(List* L, unsigned int n); //Yes
void DoneList(List* L); //Yes
void CopyList(List* L1, List* L2); //Yes
void ReadList2(List* L);
#endif

int main() {

	setlocale(LC_ALL, "Rus");

	List* A = (List*)malloc(sizeof(List));
	InitList(A);

	int a = 10;
	PutList(A, &a);
	ReadList2(A);
}

void InitList(List* L) { //Работает
	L->size = 0;
	L->Start = NULL;
	L->ptr = NULL;
	L = (List*)malloc(sizeof(List));

}

void PutList(List* L, BaseType E) { // Работает
	ptrel node = (element*)malloc(sizeof(element));

	if (L->size == 0) {
		ptrel node = (element*)malloc(sizeof(element));
		node->data = E;
		node->next = L->Start;
		L->Start = node;
	}

	node->data = E;
	node->next = L->ptr;
	L->ptr = node;
	L->size += 1;
	L->End = node;
}


void ReadList(List* L) {
	cout << *L->ptr->data;
}

void ReadList2(List* L) { //Вывод всего списка //Моя функция можете оставить ее или удалить как хотите но в методе ее нет
	ptrel node = L->ptr;
	cout << "List values: " << endl;
	for (int i = 0; i < L->size; ++i) {
		cout << "Value: " << *node->data << endl;
		node = node->next;
	}
}

void GetList(List* L, BaseType* E) { // Работает

	if (L->size == 0) {
		cout << endl << "Empty!" << endl;
		exit(1);
	}

	ptrel node = L->ptr;
	*E = node->data;
	L->size -= 1;
	L->ptr = node->next;

	free(node);
}

int FullList(List* L) {
	if (L->ptr == NULL)
		return 0;
	return 1;
}

void EndPtr(List* L) {
	L->ptr = L->Start;
}

void BeginPtr(List* L) {
	L->ptr = L->End;
}

int Count(List* L) {
	return L->size;
}

void MovePtr(List* L) {
	ptrel node = L->ptr;
	node = node->next;
	L->ptr = node;
}

int EndList(List* L) {
	if (L->ptr == L->End) {
		return 1;
	}
	return 0;
}

void MoveTo(List* L, unsigned int n) {
	ptrel node = L->ptr;
	for (int i = 0; i < n; ++i)
	{
		*node->data;
		node = node->next;
		L->ptr = node;
	}
}

void DoneList(List* L) {
	delete L;
}

void CopyList(List* L1, List* L2) {
	*L2 = *L1;
}

