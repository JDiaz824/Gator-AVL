#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_set>
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
	tree.insert("Jo2han", "12345678");

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "unsuccessful");
}

TEST_CASE("Short ID", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("Johan", "1234567");

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "unsuccessful");
}

TEST_CASE("Long ID", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("Johan", "123456789");

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "unsuccessful");
}

TEST_CASE("Invalid ID", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("Johan", "17sf39f8");

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "unsuccessful");
}

TEST_CASE("Invalid Name & ID", "[flag]"){
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("Jo23an", "17sf39f8");

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "unsuccessful");
}

TEST_CASE("AVL Insert", "[flag]"){
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("Johan", "12345678");
	tree.insert("Gerald", "23456789");
	tree.insert("Pablo", "34567890");
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successfulsuccessfulsuccessfulJohan, Gerald, Pablo");
}

TEST_CASE("Delete nonexistent node", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("Johan", "12345678");
	tree.insert("Gerald", "23456789");
	tree.insert("Pablo", "34567890");
	tree.remove("11223344");

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successfulsuccessfulsuccessfulunsuccessful");
}

TEST_CASE("Search nonexistent node", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("Johan", "12345678");
	tree.insert("Gerald", "23456789");
	tree.insert("Pablo", "34567890");
	tree.search("David");

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successfulsuccessfulsuccessfulunsuccessful");
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
	tree.insert("C", "30000000");
	tree.insert("B", "20000000");
	tree.insert("A", "10000000");
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successfulsuccessfulsuccessfulA, B, C");
}

TEST_CASE("Rotate Right-Right", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("A", "10000000");
	tree.insert("B", "20000000");
	tree.insert("C", "30000000");
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successfulsuccessfulsuccessfulA, B, C");
}

TEST_CASE("Rotate Left-Right", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("C", "30000000");
	tree.insert("A", "10000000");
	tree.insert("B", "20000000");
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successfulsuccessfulsuccessfulA, B, C");
}

TEST_CASE("Rotate Right-Left", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("A", "10000000");
	tree.insert("C", "30000000");
	tree.insert("B", "20000000");
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successfulsuccessfulsuccessfulA, B, C");
}

TEST_CASE("Deletion (no children)", "[flag]") {
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("A", "10000000");
	tree.insert("C", "30000000");
	tree.insert("B", "20000000");
	tree.remove("30000000");
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == "successfulsuccessfulsuccessfulsuccessfulA, B");
}

TEST_CASE("Deletion (one child)", "[flag]") {
	string successes = "";
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("A", "10000000");
	successes += "successful";
	tree.insert("C", "30000000");
	successes += "successful";
	tree.insert("B", "20000000");
	successes += "successful";
	tree.insert("D", "40000000");
	successes += "successful";
	tree.remove("30000000");
	successes += "successful";
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == successes + "A, B, D");
}

TEST_CASE("Deletion (two children)", "[flag]") {
	string successes = "";
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	tree.insert("A", "10000000");
	successes += "successful";
	tree.insert("C", "30000000");
	successes += "successful";
	tree.insert("B", "20000000");
	successes += "successful";
	tree.insert("D", "35000000");
	successes += "successful";
	tree.insert("E", "25000000");
	successes += "successful";
	tree.remove("30000000");
	successes += "successful";
	tree.printInorder();

	cout.rdbuf(buffer);

	REQUIRE(output.str() == successes + "A, B, E, D");
}

TEST_CASE("100 Nodes", "[flag]"){
	string successes = "";
	ostringstream output;
	streambuf* buffer = cout.rdbuf();
	cout.rdbuf(output.rdbuf());

	AVLTree tree;
	string expected = "";

	for(int i = 10000000; i < 10000100; i++)
	{
		tree.insert("test", to_string(i));
		expected += "successful";
	}

	int count = 0;
	unordered_set<int> idList;
	while (count < 10) {
		int randomNode = rand() % 101 + 10000000;
		if (idList.find(randomNode) != idList.end()) {
			continue;
		}
		else {
			idList.insert(randomNode);
			tree.remove(to_string(randomNode));
			expected += "successful";
			count++;
		}
	}

	cout.rdbuf(buffer);
	REQUIRE(output.str() == expected);
}
