// #include <catch2/catch_test_macros.hpp>
// #include <iostream>
// #include <sstream>
// #include <algorithm>
// #include <unordered_set>
// #include <vector>
//
// #include "AVL.h"
//
// using namespace std;
//
// //stringstream implementation obtained from FAQ, Q.14
//
// TEST_CASE("Invalid Name", "[flag]"){
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("Jo2han", "12345678");
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "unsuccessful\n");
// }
//
// TEST_CASE("Short ID", "[flag]") {
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("Johan", "1234567");
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "unsuccessful\n");
// }
//
// TEST_CASE("Long ID", "[flag]") {
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("Johan", "123456789");
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "unsuccessful\n");
// }
//
// TEST_CASE("Invalid ID", "[flag]") {
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("Johan", "17sf39f8");
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "unsuccessful\n");
// }
//
// TEST_CASE("Invalid Name & ID", "[flag]"){
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("Jo23an", "17sf39f8");
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "unsuccessful\n");
// }
//
// TEST_CASE("AVL Insert", "[flag]"){
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("Johan", "12345678");
// 	tree.insert("Gerald", "23456789");
// 	tree.insert("Pablo", "34567890");
// 	tree.printInorder();
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nJohan, Gerald, Pablo\n");
// }
//
// TEST_CASE("Delete nonexistent node", "[flag]") {
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("Johan", "12345678");
// 	tree.insert("Gerald", "23456789");
// 	tree.insert("Pablo", "34567890");
// 	tree.remove("11223344");
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nunsuccessful\n");
// }
//
// TEST_CASE("Search nonexistent node", "[flag]") {
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("Johan", "12345678");
// 	tree.insert("Gerald", "23456789");
// 	tree.insert("Pablo", "34567890");
// 	tree.search("David");
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nunsuccessful\n");
// }
//
// TEST_CASE("printInorder with no nodes", "[flag]") {
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.printInorder();
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "");
// }
//
// TEST_CASE("Rotate Left-Left", "[flag]") {
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("C", "30000000");
// 	tree.insert("B", "20000000");
// 	tree.insert("A", "10000000");
// 	tree.printInorder();
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nA, B, C\n");
// }
//
// TEST_CASE("Rotate Right-Right", "[flag]") {
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("A", "10000000");
// 	tree.insert("B", "20000000");
// 	tree.insert("C", "30000000");
// 	tree.printInorder();
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nA, B, C\n");
// }
//
// TEST_CASE("Rotate Left-Right", "[flag]") {
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("C", "30000000");
// 	tree.insert("A", "10000000");
// 	tree.insert("B", "20000000");
// 	tree.printInorder();
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nA, B, C\n");
// }
//
// TEST_CASE("Rotate Right-Left", "[flag]") {
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("A", "10000000");
// 	tree.insert("C", "30000000");
// 	tree.insert("B", "20000000");
// 	tree.printInorder();
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nA, B, C\n");
// }
//
// TEST_CASE("Deletion (no children)", "[flag]") {
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("A", "10000000");
// 	tree.insert("C", "30000000");
// 	tree.insert("B", "20000000");
// 	tree.remove("30000000");
// 	tree.printInorder();
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == "successful\nsuccessful\nsuccessful\nsuccessful\nA, B\n");
// }
//
// TEST_CASE("Deletion (one child)", "[flag]") {
// 	string successes = "";
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("A", "10000000");
// 	successes += "successful\n";
// 	tree.insert("C", "30000000");
// 	successes += "successful\n";
// 	tree.insert("B", "20000000");
// 	successes += "successful\n";
// 	tree.insert("D", "40000000");
// 	successes += "successful\n";
// 	tree.remove("30000000");
// 	successes += "successful\n";
// 	tree.printInorder();
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == successes + "A, B, D\n");
// }
//
// TEST_CASE("Deletion (two children)", "[flag]") {
// 	string successes = "";
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	tree.insert("A", "10000000");
// 	successes += "successful\n";
// 	tree.insert("C", "30000000");
// 	successes += "successful\n";
// 	tree.insert("B", "20000000");
// 	successes += "successful\n";
// 	tree.insert("D", "35000000");
// 	successes += "successful\n";
// 	tree.insert("E", "25000000");
// 	successes += "successful\n";
// 	tree.remove("30000000");
// 	successes += "successful\n";
// 	tree.printInorder();
//
// 	cout.rdbuf(buffer);
//
// 	REQUIRE(output.str() == successes + "A, B, E, D\n");
// }
//
// TEST_CASE("100 Nodes", "[flag]"){
// 	string successes = "";
// 	ostringstream output;
// 	streambuf* buffer = cout.rdbuf();
// 	cout.rdbuf(output.rdbuf());
//
// 	AVLTree tree;
// 	string expected = "";
//
// 	for(int i = 10000000; i < 10000100; i++)
// 	{
// 		tree.insert("test", to_string(i));
// 		expected += "successful\n";
// 	}
//
// 	int count = 0;
// 	unordered_set<int> idList;
// 	while (count < 10) {
// 		int randomNode = rand() % 101 + 10000000;
// 		if (idList.find(randomNode) != idList.end()) {
// 			continue;
// 		}
// 		else {
// 			idList.insert(randomNode);
// 			tree.remove(to_string(randomNode));
// 			expected += "successful\n";
// 			count++;
// 		}
// 	}
//
// 	cout.rdbuf(buffer);
// 	REQUIRE(output.str() == expected);
// }
