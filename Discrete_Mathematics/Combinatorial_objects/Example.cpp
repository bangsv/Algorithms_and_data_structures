#include "Header_Combin.h" 

int main(){
	vec_int subset;
	int n = 3;
	std::cout << "Number subsets:" << std::endl;
	number_subset(1, n, subset);

	for (int i = 0; i < n; i++)
		subset.push_back(i + 1);

	std::cout << std::endl << "Combinations:" << std::endl;

	int k = 2;
	Print(subset, k);
	while (Combinations(subset, n, k))
		Print(subset, k);

	std::cout << std::endl << "Permutations:" << std::endl;
	subset.clear();
	
	for (int i = 0; i < n; i++)
		subset.push_back(i + 1);

	Print(subset, n);
	while (Permutations(subset, n))
		Print(subset, n);
}
