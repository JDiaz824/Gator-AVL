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

int AVLTree::getHeight(treeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        return root->height;
    }
}

AVLTree::treeNode* AVLTree::insert(treeNode* root, string name, int id) {
    if (root == nullptr) {
        return new treeNode(name, id);
    }
    else if (id < root->id) {
        root->left = insert(root->left, name, id);
    }
    else {
        root->right = insert(root->right, name, id);
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

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
    if (root == nullptr) {
        return root;
    }
    else if (root->id == id) {
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
        else if (root->left != nullptr) {
            treeNode* temp = root;
            root = root->left;
            delete temp;
            count++;
        }
        else if (root->right != nullptr) {
            treeNode* temp = root;
            root = root->right;
            delete temp;
            count++;
        }
        else {
            delete root;
            root = nullptr;
            count++;
        }
    }
    else if (id < root->id) {
        root->left = remove(root->left, id, count);
    }
    else if (id > root->id) {
        root->right = remove(root->right, id, count);
    }

    if (root == nullptr) {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

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
    if (root == nullptr) {
        cout << "unsuccessful" << endl;
        return;
    }
    else if (id == root->id) {
        cout << root->name << endl;
        return;
    }
    else if (id < root->id) {
        search(root->left, id);
    }
    else {
        search(root->right, id);
    }
}

void AVLTree::search(treeNode* root, string name, vector<int> &idList) {
    if (root == nullptr) {
        return;
    }
    else if (root->name == name) {
        idList.push_back(root->id);
    }
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

AVLTree::treeNode* AVLTree::removeInorder(treeNode* root, int N, int &count) {
    if (root == nullptr) {
        return nullptr;
    }

    removeInorder(root->left, N, count);
    count++;

    if (N == count) {
        if (root->left != nullptr && root->right != nullptr) {
            treeNode* temp = root->right;
            while (temp->left != nullptr) {
                temp = temp->left;
            }

            root->id = temp->id;
            root->name = temp->name;

            root->right = remove(root->right, temp->id, count);
        }
        else if (root->left != nullptr) {
            treeNode* temp = root;
            root = root->left;
            delete temp;
        }
        else if (root->right != nullptr) {
            treeNode* temp = root;
            root = root->right;
            delete temp;
        }
        else {
            delete root;
            root = nullptr;
        }
    }
    else if (N > count) {
        removeInorder(root->right, N, count);
    }

    if (root == nullptr) {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

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





void AVLTree::insert(string name, string id) {
    if (idList.find(id) != idList.end() || !validName(name) || !validID(id)) {
        cout << "unsuccessful";
    }
    else {
        this->root = insert(this->root, name, stoi(id));
        cout << "successful";
        idList.insert(id);
    }
}
void AVLTree::remove(string id) {
    int count = 0;

    if (validID(id)) {
        this->root = remove(this->root, stoi(id), count);
    }

    if (count > 0) {
        cout << "successful";
    }
    else {
        cout << "unsuccessful";
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
            cout << "unsuccessful";
        }
        else {
            for (int id : idList) {
                cout << id << endl;
            }
        }
    }
    else {
        cout << "unsuccessful";
    }

}
void AVLTree::printInorder() {
    vector<string> nameList;
    printInorder(this->root, nameList);

    for (size_t i = 0; i < nameList.size(); i++) {
        if (i + 1 >= nameList.size()) {
            cout << nameList[i];
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
            cout << nameList[i];
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
            cout << nameList[i];
        }
        else {
            cout << nameList[i] << ", ";
        }
    }
}
void AVLTree::printLevelCount() {
    if (this->root == nullptr) {
        cout << "0" << endl;
    }
    else {
        cout << this->root->height << endl;
    }
}
void AVLTree::removeInorder(int N) {
    int count = -1;
    this->root = removeInorder(this->root, N, count);
    if (count == N) {
        cout << "successful";
    }
    else {
        cout << "unsuccessful";
    }
}



bool AVLTree::validName(string name) {
    for (char c : name) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == ' '))) {
            return false;
        }
    }
    return true;
}
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