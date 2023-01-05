#include <iostream>
#include "Header_set.h"

int main() {

	Set A = { 1,3,5 };
	Set B = { 1,2,6,7 };
	Set C = { 8,9 };
	Set Answer;

	A.setUnivers(10);
	B.setUnivers(10);
	C.setUnivers(10);

	std::cout << "Our sets:\nA - 1) " << A
		<< "\nB - 2) " << B << "\nC - 3) " << C << std::endl;

	std::cout << "The equation: (C | A ) ^ (B & A)" << std::endl;

	Answer = (C | A) ^ (B & A);

	std::cout << "Answer: " << Answer << std::endl;

	std::cout << "!Answer: " << !Answer << std::endl;

}
