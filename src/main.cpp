#include "AVL.h"
#include <iostream>
#include <sstream>

using namespace std;

//Used to remove quotation marks if applicable to input
string removeQuotes(string &input) {
	if (input.length() >= 2 && input.front() == '"' && input.back() == '"') {
		return input.substr(1, input.length() - 2);
	}
	return input;
}

int main(){
	AVLTree tree;

	//Used in the loop to make sure the proper number of functions are able to be done
	int count;
	cin >> count;

	for (int i = 0; i < count; i++) {
		string function;
		cin >> function;

		//Function calls
		if (function == "insert") {
			string name;
			string id;
			cin >> name >> id;
			tree.insert(removeQuotes(name), id);
		}
		else if (function == "remove") {
			string id;
			cin >> id;
			tree.remove(id);
		}
		else if (function == "search") {
			string input;
			cin >> input;
			tree.search(removeQuotes(input));
		}
		else if (function == "printInorder") {
			tree.printInorder();
		}
		else if (function == "printPreorder") {
			tree.printPreorder();
		}
		else if (function == "printPostorder") {
			tree.printPostorder();
		}
		else if (function == "printLevelCount") {
			tree.printLevelCount();
		}
		else if (function == "removeInorder") {
			int n;
			cin >> n;
			tree.removeInorder(n);
		}
		else {
			cout << "unsuccessful" << endl;
		}
	}

	return 0;
}
