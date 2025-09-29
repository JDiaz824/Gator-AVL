//
// Created by Johan on 9/19/2025.
//

#include "AVL.h"
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;

AVLTree::AVLTree() {
    root = nullptr;
};

AVLTree::~AVLTree() {
    deleteTree(root);
};

//The following are my helper functions

int AVLTree::getHeight(treeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        return root->height;
    }
}

//Some coding and fundamental ideas obtained from Sept 16, second lecture
AVLTree::treeNode* AVLTree::insert(treeNode* root, string name, int id) {
    //Add root to tree
    if (root == nullptr) {
        return new treeNode(name, id);
    }
    else if (id < root->id) {
        root->left = insert(root->left, name, id);
    }
    else {
        root->right = insert(root->right, name, id);
    }

    //Updates height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    //Rotates if needed
    if (getHeight(root->left) - getHeight(root->right) < -1) {
        if (getHeight(root->right->left) - getHeight(root->right->right) > 0) {
            return rotateRightLeft(root);
        }
        else {
            return rotateLeft(root);
        }
    }
    else if (getHeight(root->left) - getHeight(root->right) > 1) {
        if (getHeight(root->left->left) - getHeight(root->left->right) < 0) {
            return rotateLeftRight(root);
        }
        else {
            return rotateRight(root);
        }
    }

    return root;
}

AVLTree::treeNode* AVLTree::rotateLeft(treeNode* root) {
    treeNode* rightValue = root->right;
    treeNode* rightLeftValue = root->right->left;

    rightValue->left = root;
    root->right = rightLeftValue;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    rightValue->height = 1 + max(getHeight(rightValue->left), getHeight(rightValue->right));

    return rightValue;
}

AVLTree::treeNode* AVLTree::rotateRight(treeNode* root) {
    treeNode* leftValue = root->left;
    treeNode* leftRightValue = root->left->right;

    leftValue->right = root;
    root->left = leftRightValue;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    leftValue->height = 1 + max(getHeight(leftValue->left), getHeight(leftValue->right));

    return leftValue;
}

AVLTree::treeNode* AVLTree::rotateLeftRight(treeNode* root) {
    root->left = rotateLeft(root->left);

    return rotateRight(root);
}

AVLTree::treeNode* AVLTree::rotateRightLeft(treeNode* root) {
    root->right = rotateRight(root->right);

    return rotateLeft(root);
}

AVLTree::treeNode* AVLTree::remove(treeNode* root, int id, int &count) {
    //Base case
    if (root == nullptr) {
        return root;
    }
    //id is found
    else if (root->id == id) {
        //Case where root has 2 children
        if (root->left != nullptr && root->right != nullptr) {
            treeNode* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            root->id = temp->id;
            root->name = temp->name;

            root->right = remove(root->right, temp->id, count);

            count++;
        }
        //Case where root has 1 child (left node)
        else if (root->left != nullptr) {
            treeNode* temp = root;
            root = root->left;
            delete temp;
            count++;
        }
        //Case where root has 1 child (right node)
        else if (root->right != nullptr) {
            treeNode* temp = root;
            root = root->right;
            delete temp;
            count++;
        }
        //Case where root has no children
        else {
            delete root;
            root = nullptr;
            count++;
        }
    }
    //Goes left if id is smaller than current id
    else if (id < root->id) {
        root->left = remove(root->left, id, count);
    }
    //Goes right if id is greater than current id
    else if (id > root->id) {
        root->right = remove(root->right, id, count);
    }

    //Base case
    if (root == nullptr) {
        return root;
    }

    //Update height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    //Rotation logic if necessary
    if (getHeight(root->left) - getHeight(root->right) < -1) {
        if (getHeight(root->right->left) - getHeight(root->right->right) > 0) {
            return rotateRightLeft(root);
        }
        else {
            return rotateLeft(root);
        }
    }
    else if (getHeight(root->left) - getHeight(root->right) > 1) {
        if (getHeight(root->left->left) - getHeight(root->left->right) < 0) {
            return rotateLeftRight(root);
        }
        else {
            return rotateRight(root);
        }
    }

    return root;
}

void AVLTree::search(treeNode* root, int id) {
    //Returns unsuccessful if id not found
    if (root == nullptr) {
        cout << "unsuccessful\n" << endl;
        return;
    }
    //Return succesful if id is found
    else if (id == root->id) {
        cout << root->name << endl;
        return;
    }
    //Goes left is id is smaller than current id
    else if (id < root->id) {
        search(root->left, id);
    }
    //Goes right if id is greater than current id
    else {
        search(root->right, id);
    }
}

void AVLTree::search(treeNode* root, string name, vector<int> &idList) {
    //Base case
    if (root == nullptr) {
        return;
    }
    //If name is found, pushes back id to list
    else if (root->name == name) {
        idList.push_back(root->id);
    }
    //Recursion to go through the whole tree
    search(root->left, name, idList);
    search(root->right, name, idList);
}

void AVLTree::printInorder(treeNode* root, vector<string> &nameList) {
    if (root == nullptr) {
        return;
    }
    printInorder(root->left, nameList);
    nameList.push_back(root->name);
    printInorder(root->right, nameList);
}

void AVLTree::printPreorder(treeNode* root, vector<string> &nameList) {
    if (root == nullptr) {
        return;
    }
    nameList.push_back(root->name);
    printPreorder(root->left, nameList);
    printPreorder(root->right, nameList);
}

void AVLTree::printPostorder(treeNode* root, vector<string> &nameList) {
    if (root == nullptr) {
        return;
    }
    printPostorder(root->left, nameList);
    printPostorder(root->right, nameList);
    nameList.push_back(root->name);
}

AVLTree::treeNode* AVLTree::removeInorder(treeNode* root, int N, int &count, bool &deleted) {
    //Base case
    if (root == nullptr) {
        return root;
    }

    root->left = removeInorder(root->left, N, count, deleted);

    //Base case if the desired root was already deleted
    if (deleted) {
        return root;
    }

    //Deletes root if found
    if (N == count && !deleted) {
        int tempCount = 0;
        root = remove(root, root->id, tempCount);
        deleted = true;
        return root;
    }

    count++;

    root->right = removeInorder(root->right, N, count, deleted);
    return root;
}

//Used to check if a name meets the requirements
bool AVLTree::validName(string name) {
    for (char c : name) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' '))) {
            return false;
        }
    }
    return true;
}

//Used to check if a string meets the requirements
bool AVLTree::validID(string id) {
    for (char c : id) {
        if (!(c >= '0' && c <= '9')) {
            return false;
        }
    }
    if (id.length() != 8) {
        return false;
    }
    return true;
}

void AVLTree::deleteTree(treeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

//The following are my functions that are called in main, referencing their respective helpers

void AVLTree::insert(string name, string id) {
    if (idList.find(id) != idList.end() || !validName(name) || !validID(id)) {
        cout << "unsuccessful\n";
    }
    else {
        this->root = insert(this->root, name, stoi(id));
        cout << "successful\n";
        //idList is used to make sure ids are unique
        idList.insert(id);
    }
}

void AVLTree::remove(string id) {
    int count = 0;

    if (validID(id)) {
        this->root = remove(this->root, stoi(id), count);
    }

    if (count > 0) {
        cout << "successful\n";
    }
    else {
        cout << "unsuccessful\n";
    }
}

void AVLTree::search(string input) {
    if (validID(input)) {
        search(this->root, stoi(input));
    }
    else if (validName(input)) {
        vector<int> idList;
        search(this->root, input, idList);

        if (idList.size() == 0) {
            cout << "unsuccessful\n";
        }
        else {
            for (int id : idList) {
                cout << id << endl;
            }
        }
    }
    else {
        cout << "unsuccessful\n";
    }

}

void AVLTree::printInorder() {
    vector<string> nameList;
    printInorder(this->root, nameList);

    for (size_t i = 0; i < nameList.size(); i++) {
        if (i + 1 >= nameList.size()) {
            cout << nameList[i] << endl;
        }
        else {
            cout << nameList[i] << ", ";
        }
    }
}

void AVLTree::printPreorder() {
    vector<string> nameList;
    printPreorder(this->root, nameList);

    for (size_t i = 0; i < nameList.size(); i++) {
        if (i + 1 >= nameList.size()) {
            cout << nameList[i] << endl;
        }
        else {
            cout << nameList[i] << ", ";
        }
    }
}

void AVLTree::printPostorder() {
    vector<string> nameList;
    printPostorder(this->root, nameList);

    for (size_t i = 0; i < nameList.size(); i++) {
        if (i + 1 >= nameList.size()) {
            cout << nameList[i] << endl;
        }
        else {
            cout << nameList[i] << ", ";
        }
    }
}

void AVLTree::printLevelCount() {
    //Prints 0 if there's no nodes
    if (this->root == nullptr) {
        cout << "0" << endl;
    }
    //Prints the height of the root, which is how many levels there are
    else {
        cout << this->root->height << endl;
    }
}

void AVLTree::removeInorder(int N) {
    int count = 0;
    bool deleted = false;
    this->root = removeInorder(this->root, N, count, deleted);
    if (deleted) {
        cout << "successful\n";
    }
    else {
        cout << "unsuccessful\n";
    }
}