#include "AVL.h"
#include <iostream>

using namespace std;

int main(){
	cout << "Hello AVL!\n";

	AVLTree tree;
	tree.insert("A", 10000000);
	tree.insert("B", 12000000);
	tree.insert("C", 13000000);


	tree.printPostorder();

	return 0;
}
