#include <iostream>
#include "HeaderTree.h"

using namespace std;

const int TreeOk = 0;
const int TreeNotMem = 1;
const int TreeUnder = 2;

#define Index 1000

typedef void* BaseType;
typedef unsigned PtrEl;

typedef struct element {
	BaseType data;
	PtrEl LSon;
	PtrEl RSon;
};

typedef element Mem[Index];

typedef Mem Pmem;
typedef PtrEl* Tree;

short TreeError;
Pmem Pbuf; //указатель на массив

unsigned Size; //размер массива
unsigned SizeEl;

// инициализация дерева ✔
void InitTree(Tree& T, unsigned size) {
	T = (Tree)new Tree[Index];
	Size = size;
	SizeEl = 0;

	for (int i = 0; i < size; i++)
		Pbuf[i].data = new BaseType[Index];
}

//создание корня
void CreateRoot(Tree& T) { // ✔
	*T = 0;
	Pbuf[(int)*T].LSon = -1;
	Pbuf[(int)*T].RSon = -1;
	Pbuf[(int)*T].data = (BaseType)-1;
}

//запись данных ✔
void WriteDataTree(Tree& T, BaseType E) {

	if (Pbuf[(int)*T].RSon != (PtrEl)-1) {
		int a = *T;
		++T;
		*T = a + 1;
	}

	if (Pbuf[(int)*T].data != (BaseType)-1) {

		if (Pbuf[(int)*T].LSon == (PtrEl)-1) {


			Pbuf[(int)*T].LSon = (int)*T * 2 + 1; // Добавили адрес Л сына
			Pbuf[(int)*T * 2 + 1].data = (BaseType*)E; // Записали его данные

			//Отмечаем что у Л сына нет еще сыновей
			Pbuf[(int)*T * 2 + 1].LSon = (PtrEl)-1;
			Pbuf[(int)*T * 2 + 1].RSon = (PtrEl)-1;
			//Увеличиваем кол-во элементов
			SizeEl += 1;
			return;
		}

		if (Pbuf[(int)*T].RSon == (PtrEl)-1) {


			Pbuf[(int)*T].RSon = (int)*T * 2 + 2;
			Pbuf[(int)*T * 2 + 2].data = (BaseType*)E;

			//Отмечаем что у П сына нет еще сыновей
			Pbuf[(int)*T * 2 + 2].LSon = (PtrEl)-1;
			Pbuf[(int)*T * 2 + 2].RSon = (PtrEl)-1;
			SizeEl += 1;
			return;
		}
	}

	//Добавляем первый элемент(Корень)
	if (SizeEl == 0) {
		Pbuf[(int)*T].data = (BaseType*)E;
		Pbuf[(int)*T].LSon = (PtrEl)-1;
		Pbuf[(int)*T].RSon = (PtrEl)-1;
		SizeEl += 1;
	}
}

//чтение 
void ReadDataTree(Tree& T, BaseType* E) { // ✔
	cout << Pbuf[(int)*T].data;
	*E = Pbuf[(int)*T].data;
}

//1 — есть левый сын, 0 — нет 
int IsLSon(Tree& T) {// ✔
	return Pbuf[(int)*T].LSon != (PtrEl)-1 ? 1 : 0;
}

//1 — есть правый сын, 0 — нет
int IsRSon(Tree& T) { // ✔
	return Pbuf[(int)*T].RSon != (PtrEl)-1 ? 1 : 0;
}

// перейти к левому сыну, где T — ад-рес ячейки, содержащей адрес текущей вершины, 
//TS — адрес ячейки, со - держащей адрес корня левого поддерева(левого сына)
void MoveToLSon(Tree& T, Tree& TS) { //✔
	if (!IsLSon(T))
		return;

	*TS = Pbuf[(int)*T].LSon;
}

//перейти к правому сыну
void MoveToRSon(Tree& T, Tree& TS) { //✔

	if (!IsRSon(T))
		return;

	*TS = Pbuf[(int)*T].RSon;
}

//1 — пустое дерево,0 — не пустое
int IsEmptyTree(Tree& T) { //✔
	return SizeEl == 0 ? 1 : 0;
}

//удаление листа
void DelTree(Tree& T) { //✔
	if (IsLSon(T) == 1) {
		Pbuf[Pbuf[*T].LSon].data = NULL;
		delete Pbuf[Pbuf[*T].LSon].data;
		Pbuf[(int)*T].LSon = -1;
		SizeEl -= 1;
	}
	if (IsRSon(T) == 1) {
		Pbuf[Pbuf[*T].RSon].data = NULL;
		delete Pbuf[Pbuf[*T].RSon].data;
		Pbuf[(int)*T].RSon = -1;
		SizeEl -= 1;
	}
}

void outPut(Tree& T) {
	for (int i = 0; i < (int)*T + 1; i++) {
		cout << "Father: " << (int) Pbuf[i].data << " LSon: " << (int)Pbuf[i * 2 + 1].data <<
			" RSon: " << (int)Pbuf[i * 2 + 2].data << endl;
	}
}

bool checkLeaf(int tree) { // Проверка на лист
	return (Pbuf[tree].LSon == (PtrEl)-1 && Pbuf[tree].RSon == (PtrEl)-1) ? false : true;
}

void outputAllLeaf(Tree& tree) {
	int i = 0;
	while (i != SizeEl) {
		if (!checkLeaf(i)) {
			cout << (int)Pbuf[i].data << " ";
		}
		i += 1;
	}
}

int div_up(int x, int y) {
	return (x + y - 1) / y;
}


int AllWay(int Size, Tree& tree) {
	if (Size == 0)
		return 0;

	if (!checkLeaf(Size)) {
		cout << (int)Pbuf[Size].data << " ";
		for (int i = Size; i != 0; i = div_up(i, 2) - 1) {
			cout << (int)Pbuf[div_up(i, 2) - 1].data << " ";
		}
		cout << endl;
	}

	return AllWay(Size - 1, tree);
}
