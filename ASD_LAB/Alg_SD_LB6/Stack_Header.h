#pragma once
typedef int BaseType_Stack;

typedef struct element_Stack* ptrel_Stack;

typedef struct element_Stack {
	BaseType_Stack data_Stack;
	ptrel_Stack next_Stack;
};

typedef struct List_Stack {
	ptrel_Stack Start_Stack; // ����� ������ ������� 
	ptrel_Stack ptr_Stack; // ��������� �� ����
	unsigned int size_Stack; // ������
};

typedef List_Stack Stack;

void InitStack(Stack* s, unsigned Size); /* ������������� ����� */
void PutStack(Stack* s, BaseType_Stack E); // ��������� ������� � ���� 
unsigned GetStack(Stack* s); // ������� ������� �� ����� 
bool EmptyStack(Stack* s); // ��������: ���� ����? 
void ReadStack(Stack* s); /* ��������� ������� �� ������� ����� */
void DoneStack(Stack* s); // ���������� ���� 
