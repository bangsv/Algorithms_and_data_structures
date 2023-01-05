#include <iostream>
#include "Fifo_Header.h"

using namespace std;

void InitFifo(Fifo* f) { // ������������� ������� 
	f->ptr_Fifo = NULL;
	f->Start_Fifo = f->ptr_Fifo;
	f->size_Fifo = 0;
}

void PutFifo(Fifo* f, BaseType_Fifo E) { /* ��������� ������� � ������� */
	ptrel_Fifo node = (element_Fifo*)malloc(sizeof(element_Fifo));

	node->data = E;
	if (f->Start_Fifo != NULL) {
		f->Start_Fifo->next = node;
	}
	else {
		f->ptr_Fifo = node;
	}
	f->Start_Fifo = node;
	f->size_Fifo += 1;
}

unsigned GetFifo(Fifo* f) { /* ������� ������� �� ������� */

	if (f->size_Fifo == 0) {
		return 0;
	}

	ptrel_Fifo node = (element_Fifo*)malloc(sizeof(element_Fifo));

	node = f->ptr_Fifo;
	unsigned E = node->data;

	f->size_Fifo -= 1;
	f->ptr_Fifo = node->next;

	free(node);

	if (f->size_Fifo == 0) {
		f->ptr_Fifo = NULL;
		f->Start_Fifo = NULL;
	}

	return E;
}


void ReadFifo(Fifo* f, BaseType_Fifo E) {  // ��������� ������� 
	ptrel_Fifo node = f->ptr_Fifo;

	for (int i = 0; i < E; i++) {
		node = node->next;
	}

	cout << node->data;
}

bool EmptyFifo(Fifo* f) { // ��������, ����� �� �������? 
	return f->size_Fifo == 0 ? false : true;
}
void DoneFifo(Fifo* f) {// ��������� ������� 
	delete[]  f;
}