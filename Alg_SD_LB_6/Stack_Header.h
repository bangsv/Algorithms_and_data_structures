#pragma once
typedef int BaseType_Stack;

typedef struct element_Stack* ptrel_Stack;

typedef struct element_Stack {
	BaseType_Stack data_Stack;
	ptrel_Stack next_Stack;
};

typedef struct List_Stack {
	ptrel_Stack Start_Stack; // Самый первый элемент 
	ptrel_Stack ptr_Stack; // Указатель на инфу
	unsigned int size_Stack; // Размер
};

typedef List_Stack Stack;

void InitStack(Stack* s, unsigned Size); /* Инициализация стека */
void PutStack(Stack* s, BaseType_Stack E); // Поместить элемент в стек 
unsigned GetStack(Stack* s); // Извлечь элемент из стека 
bool EmptyStack(Stack* s); // Проверка: стек пуст? 
void ReadStack(Stack* s); /* Прочитать элемент из вершины стека */
void DoneStack(Stack* s); // Уничтожить стек 
