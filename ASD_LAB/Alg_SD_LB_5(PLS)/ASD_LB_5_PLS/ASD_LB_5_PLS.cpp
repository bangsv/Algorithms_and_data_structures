#include <iostream>

using namespace std;

#if !defined(__LIST6_H)

#define SizeList 100

const int ListOk = 0;
const int ListNotMem = 1;
const int ListUnder = 2;
const int ListEnd = 3;
typedef void* BaseType;
typedef unsigned ptrel;

typedef struct List {
	BaseType MemList[SizeList];
	ptrel ptr;
	unsigned int N;  // длина списка 
	unsigned int Size;// размер массива 
};

short ListError;

void InitList(List* L) {

	*L->MemList = new BaseType[SizeList];

	L->ptr = NULL;
	L->Size = SizeList;
	L->N = NULL;

}


void PutList(List* L, BaseType E) {
	L->ptr = L->N;

	L->MemList[L->ptr++] = E;
	L->N += 1;
	L->ptr = NULL;
}

void CopyList(List* L1, List* L2) {
	*L2 = *L1;

}

void ReadList(List* L, BaseType* E) {
	int index = *(int*)*E;
	*E = L->MemList[index];
}

void GetList(List* L, BaseType* E) { //
	List* L2;
	L2 = (struct List*)malloc(sizeof(struct List));
	InitList(L2);
	int size = L->N;
	int j = 0;
	for (int i = 0; i < size; i++) {
		if ((BaseType)i != *E) {
			L2->MemList[j] = L->MemList[i];
			j += 1;
			L2->N += 1;
		}
	}
	CopyList(L2, L);
}


int FullList(List* L) { // проверка: список пуст 
	if (L->N == NULL) {
		ListError = ListEnd;
		return 1;
	}
	return 0;
}


void BeginPtr(List* L) { // устанановка в начало списка. 
	L->ptr = NULL;
}

void EndPtr(List* L) { //устанановка в конец списка. 
	L->ptr = L->N;
}

void MovePtr(List* L) { //переход к следующему элементу 
	L->ptr += 1;
}

void MoveTo(List* L, unsigned int n) { //переход к n-му элементу 
	L->ptr = n;
}

void DoneList(List* L) { //удаление списка. 
	delete L;
}

unsigned int Count(List* L) { // возвращает количество элементов в списке. 
	return L->N;
}

#endif

int main() {

	List* A;
	A = (struct List*)malloc(sizeof(struct List));

	List* B;
	B = (struct List*)malloc(sizeof(struct List));

	setlocale(LC_ALL, "");

	InitList(A);
	InitList(B);

	int a = 20;
	void* p = (void*)a;

	PutList(A, p);
	a = 199;
	p = (void*)a;
	PutList(A, p);

	cout << (int)A->MemList[1];
	a = 1;
	p = (void*)a;
	GetList(A, &p);

}