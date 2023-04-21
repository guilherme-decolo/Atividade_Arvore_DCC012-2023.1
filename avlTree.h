#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include "node.h"
using namespace std;

class AVLTree {
private:
    Node *root;
    Node *rightRotate(Node *y);
    Node *leftRotate(Node *x);
    void destroyTree(Node* node);
public:
    AVLTree();
    ~AVLTree();

    int getHeight(Node *N);
    Node *insert(Node *node, int key);

    void printTree(Node* node, int level);
    void print(Node* node);
};

#endif

