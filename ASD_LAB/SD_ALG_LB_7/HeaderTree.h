#pragma once
#include <iostream>

typedef void* BaseType;
typedef unsigned PtrEl;

typedef struct element;


typedef void* BaseType;
typedef unsigned PtrEl;

typedef element Mem[1000];

typedef Mem Pmem;
typedef PtrEl* Tree;
// инициализация дерева ✔
void InitTree(Tree& T, unsigned size);

//создание корня
void CreateRoot(Tree& T);

//запись данных ✔
void WriteDataTree(Tree& T, BaseType E);

//чтение 
void ReadDataTree(Tree& T, BaseType* E);

//1 — есть левый сын, 0 — нет 
int IsLSon(Tree& T);

//1 — есть правый сын, 0 — нет
int IsRSon(Tree& T);

// перейти к левому сыну, где T — ад-рес ячейки, содержащей адрес текущей вершины, 
//TS — адрес ячейки, со - держащей адрес корня левого поддерева(левого сына)
void MoveToLSon(Tree& T, Tree& TS);

//перейти к правому сыну
void MoveToRSon(Tree& T, Tree& TS);

//1 — пустое дерево,0 — не пустое
int IsEmptyTree(Tree& T);

//удаление листа
void DelTree(Tree& T);

void outPut(Tree& T);

bool checkLeaf(int tree);

void outputAllLeaf(Tree& tree);

int div_up(int x, int y);

int AllWay(int Size, Tree& tree);