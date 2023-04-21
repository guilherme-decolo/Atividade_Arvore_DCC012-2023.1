#include <iostream>
#include "avlTree.h"
#include "avlTree.cpp"
#include "node.h"
#include "node.cpp"


int main()
{
    AVLTree tree;
    Node *root = nullptr;

    root = tree.insert(root, 10);
    root = tree.insert(root, 15);
    root = tree.insert(root, 20);
    root = tree.insert(root, 25);
    root = tree.insert(root, 30);
    root = tree.insert(root, 35);
    root = tree.insert(root, 40);
    root = tree.insert(root, 45);
    root = tree.insert(root, 50);


    tree.print(root);
    cout << endl;
    tree.printTree(root, 0);

    return 0;
}