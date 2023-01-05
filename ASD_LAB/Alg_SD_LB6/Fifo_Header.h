#pragma once
typedef int BaseType_Fifo;
typedef struct element_Fifo* ptrel_Fifo;

typedef struct element_Fifo {
	BaseType_Fifo data;
	ptrel_Fifo next;
};

typedef struct List_Fifo {
	ptrel_Fifo Start_Fifo; // ����� ������ ������� 
	ptrel_Fifo ptr_Fifo; // ��������� �� ����
	unsigned int size_Fifo; // ������
};

typedef List_Fifo Fifo;

void InitFifo(Fifo* f);
void PutFifo(Fifo* f, BaseType_Fifo E);
unsigned  GetFifo(Fifo* f);
void ReadFifo(Fifo* f, BaseType_Fifo E);
bool EmptyFifo(Fifo* f);
void DoneFifo(Fifo* f);