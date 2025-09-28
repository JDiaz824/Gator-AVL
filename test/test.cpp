#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

// uncomment and replace the following with your own headers
#include "AVL.h"

using namespace std;



// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
TEST_CASE("Invalid Name", "[flag]"){
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("D4vid", 12345678);

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "unsuccessful\n");
}

TEST_CASE("Short ID", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("Johan", 1234567);

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "unsuccessful\n");
}

TEST_CASE("Long ID", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("D4vid", 123456789);

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "unsuccessful\n");
}

// TEST_CASE("Invalid ID", "[flag]") {
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("D4vid", 10000);
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "unsuccessful\n");
// }

// TEST_CASE("Invalid Name & ID", "[flag]"){
// 	string name = "J02an";
// 	string ID = "gh82ryg8";
// 	REQUIRE(name == "Johan");
// 	REQUIRE(ID == "12824358");
// }

TEST_CASE("AVL Insert", "[flag]"){
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("Johan", 12345678);
	tree.insert("Gerald", 23456789);
	tree.insert("Pablo", 34567890);
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nJohan, Gerald, Pablo\n");
}

TEST_CASE("Delete nonexistent node", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("Johan", 12345678);
	tree.insert("Gerald", 23456789);
	tree.insert("Pablo", 34567890);
	tree.remove(11223344);

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nunsuccessful\n");
}

TEST_CASE("Search nonexistent node", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("Johan", 12345678);
	tree.insert("Gerald", 23456789);
	tree.insert("Pablo", 34567890);
	tree.search("David");

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nunsuccessful\n");
}

TEST_CASE("printInorder with no nodes", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "");
}

TEST_CASE("Rotate Left-Left", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("C", 30000000);
	tree.insert("B", 20000000);
	tree.insert("A", 10000000);
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nA, B, C\n");
}

TEST_CASE("Rotate Right-Right", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("A", 10000000);
	tree.insert("B", 20000000);
	tree.insert("C", 30000000);
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nA, B, C\n");
}

TEST_CASE("Rotate Left-Right", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("C", 30000000);
	tree.insert("A", 10000000);
	tree.insert("B", 20000000);
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nA, B, C\n");
}

TEST_CASE("Rotate Right-Left", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("A", 10000000);
	tree.insert("C", 30000000);
	tree.insert("B", 20000000);
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nA, B, C\n");
}

TEST_CASE("Deletion (no children)", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("A", 10000000);
	tree.insert("C", 30000000);
	tree.insert("B", 20000000);
	tree.remove(30000000);
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nsuccessful\nA, B\n");
}

TEST_CASE("Deletion (one child)", "[flag]") {
	string successes = "";
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("A", 10000000);
	successes += "successful\n";
	tree.insert("C", 30000000);
	successes += "successful\n";
	tree.insert("B", 20000000);
	successes += "successful\n";
	tree.insert("D", 40000000);
	successes += "successful\n";
	tree.remove(30000000);
	successes += "successful\n";
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == successes + "A, B, D\n");
}

TEST_CASE("Deletion (two children)", "[flag]") {

}

// TEST_CASE("100 Nodes", "[flag]"){
// 	AVLTree inputTree;
// 	std::vector<int> expectedOutput, actualOutput;
//
// 	for(int i = 0; i < 100; i++)
// 	{
// 		int randomInput = rand();
// 		if (std::count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0)
// 		{
// 			expectedOutput.push_back(randomInput);
// 			inputTree.insert(randomInput);
// 		}
// 	}
//
// 	actualOutput = inputTree.inOrder();
// 	REQUIRE(expectedOutput.size() == actualOutput.size());
// 	std::sort(expectedOutput.begin(), expectedOutput.end());
// 	REQUIRE(expectedOutput == actualOutput);
// }
