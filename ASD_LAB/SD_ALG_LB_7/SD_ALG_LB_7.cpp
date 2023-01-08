#include <iostream>
#include "HeaderTree.h"

using namespace std;

#define SIZE 9

int main() {

	Tree tree = (Tree)new Tree[SIZE];
	InitTree(tree, SIZE);
	CreateRoot(tree);

	for (int i = 0; i < SIZE; i++)
		WriteDataTree(tree, ((BaseType)((i + 1) * 2)));

	cout << "1) Our tree: " << endl;
	outPut(tree);

	cout << endl;

	cout << "2) All Leaf: " << endl;
	outputAllLeaf(tree);

	cout << endl;

	cout << endl << "3) All way: " << endl;

	AllWay(SIZE, tree);

}
