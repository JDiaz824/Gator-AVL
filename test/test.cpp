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
	ostringstream oss;
	streambuf* p_cout_streambuf = cout.rdbuf();
	cout.rdbuf(oss.rdbuf());

	AVLTree tree;
	tree.insert("D4vid", 10000000);

	cout.rdbuf(p_cout_streambuf);

	REQUIRE(oss.str == "unsuccessful");
}

TEST_CASE("Short ID", "[flag]") {
	int ID = 1234567;
	bool rightLength = true;
	string stringID = to_string(ID);
	if (stringID.size() != 8) {
		rightLength = false;
	}
	REQUIRE_FALSE(rightLength);
}

TEST_CASE("Long ID", "[flag]") {
	int ID = 123456789;
	bool rightLength = true;
	string stringID = to_string(ID);
	if (stringID.size() != 8) {
		rightLength = false;
	}
	REQUIRE_FALSE(rightLength);
}

TEST_CASE("Invalid ID", "[flag]") {
	string ID = "o2345s78";
	REQUIRE(ID == "12345678");
}

TEST_CASE("Invalid Name & ID", "[flag]"){
	string name = "J02an";
	string ID = "gh82ryg8";
	REQUIRE(name == "Johan");
	REQUIRE(ID == "12824358");
}

TEST_CASE("AVL Insert", "[flag]"){
	AVLTree tree;
	tree.insert(tree, "a", 3);
	tree.insert(5);
	tree.insert(1);
	std::vector<int> actualOutput = tree.inOrder();
	std::vector<int> expectedOutput = {1, 3, 5};
	REQUIRE(expectedOutput.size() == actualOutput.size());
	REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Rotate Left-Left", "[flag]") {
	AVLTree tree;
	tree.insert(30);
	tree.insert(20);
	tree.insert(10);
	std::vector<int> actualOutput = tree.inOrder();
	std::vector<int> expectedOutput = {10, 20, 30};
	REQUIRE(expectedOutput.size() == actualOutput.size());
	REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Rotate Right-Right", "[flag]") {
	AVLTree tree;
	tree.insert(10);
	tree.insert(20);
	tree.insert(30);
	std::vector<int> actualOutput = tree.inOrder();
	std::vector<int> expectedOutput = {10, 20, 30};
	REQUIRE(expectedOutput.size() == actualOutput.size());
	REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Rotate Left-Right", "[flag]") {
	AVLTree tree;
	tree.insert(30);
	tree.insert(10);
	tree.insert(20);
	std::vector<int> actualOutput = tree.inOrder();
	std::vector<int> expectedOutput = {10, 20, 30};
	REQUIRE(expectedOutput.size() == actualOutput.size());
	REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("Rotate Right-Left", "[flag]") {
	AVLTree tree;
	tree.insert(10);
	tree.insert(30);
	tree.insert(20);
	std::vector<int> actualOutput = tree.inOrder();
	std::vector<int> expectedOutput = {10, 20, 30};
	REQUIRE(expectedOutput.size() == actualOutput.size());
	REQUIRE(actualOutput == expectedOutput);
}

TEST_CASE("100 Nodes", "[flag]"){
	AVLTree inputTree;
	std::vector<int> expectedOutput, actualOutput;

	for(int i = 0; i < 100; i++)
	{
		int randomInput = rand();
		if (std::count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0)
		{
			expectedOutput.push_back(randomInput);
			inputTree.insert(randomInput);
		}
	}

	actualOutput = inputTree.inOrder();
	REQUIRE(expectedOutput.size() == actualOutput.size());
	std::sort(expectedOutput.begin(), expectedOutput.end());
	REQUIRE(expectedOutput == actualOutput);
}
