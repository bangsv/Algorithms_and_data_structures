#pragma once
#include <iostream>

using namespace std;

typedef string TaskType;

typedef struct TInquiry {
	int Name; // ��� �������  // ��� �������� ��������� ��� ��� 
	unsigned Time;
	TaskType T; // ��� ������: 1 � �1, 2 � �2, 3 � �3 // � ����� ��������� ����� �������� ������
};

void generatedName(int& Name);
void Task_Generator(TInquiry* task);

bool P1(unsigned time);
bool P2(unsigned time);