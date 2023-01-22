#pragma once
#include <iostream>

using namespace std;

typedef string TaskType;

typedef struct TInquiry {
	int Name; // имя запроса  // Для удобства понимания где что 
	unsigned Time;
	TaskType T; // тип задачи: 1 — Т1, 2 — Т2, 3 — Т3 // В какой процессор будет помещена задача
};

void generatedName(int& Name);
void Task_Generator(TInquiry* task);

bool P1(unsigned time);
bool P2(unsigned time);