//
// Created by Johan on 9/19/2025.
//

#ifndef AVL_H
#define AVL_H
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class AVLTree {
private:
    struct treeNode {
        string name;
        int id;
        int height;
        treeNode *left;
        treeNode *right;
        treeNode(string name, int id) {
            this->name = name;
            this->id = id;
            height = 1;
            left = nullptr;
            right = nullptr;
        };
    };

    //Helper Functions:

    treeNode* root;
    unordered_set<string> idList;

    treeNode* insert(treeNode* root, string name, int id);
    treeNode* remove(treeNode* root, int id, int &count);

    int getHeight(treeNode* root);
    treeNode* rotateLeft(treeNode* root);
    treeNode* rotateRight(treeNode* root);
    treeNode* rotateLeftRight(treeNode* root);
    treeNode* rotateRightLeft(treeNode* root);

    void search(treeNode* root, int id);
    void search(treeNode* root, string name, vector<int> &idList);

    void printInorder(treeNode* root, vector<string> &nameList);
    void printPreorder(treeNode* root, vector<string> &nameList);
    void printPostorder(treeNode* root, vector<string> &nameList);

    treeNode* removeInorder(treeNode* root, int N, int &count, bool &deleted);

    bool validName(string name);
    bool validID(string id);

    void deleteTree(treeNode* root);
public:
    AVLTree();
    ~AVLTree();

    //Main functions:

    void insert(string name, string id);
    void remove(string id);
    void search(string input);
    void printInorder();
    void printPreorder();
    void printPostorder();
    void printLevelCount();
    void removeInorder(int N);
};


#endif //AVL_H
