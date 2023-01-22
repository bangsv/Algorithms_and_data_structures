#include "Task_Header.h"

string TTASK[3] = { "T1","T2","T3" };

string lang = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void generatedName(int& Name) {
	Name = rand() % 10+20;
}

void Task_Generator(TInquiry* task) {
	generatedName(task->Name);
	task->Time;
	task->T = TTASK[rand() % 3];
}

bool P1(unsigned time) {
	while (time != 0)
		time -= 1;
	return true;
}

bool P2(unsigned time) {
	while (time != 0)
		time -= 1;
	return true;
}