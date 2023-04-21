#include "avlTree.h"
#include <iostream>
using namespace std;
#include "node.h"

AVLTree::AVLTree() {
    root = nullptr;
}
AVLTree::~AVLTree() {
    destroyTree(root);
}
void AVLTree::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

Node* AVLTree::leftRotate(Node* node) {
    Node* rightChild = node->right;
    Node* aux = rightChild->left;
    // Rotação
    rightChild->left = node;
    node->right = aux;

    // Atualiza altura
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    rightChild->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    return rightChild;
}

Node* AVLTree::rightRotate(Node* node) {
    Node* leftChild = node->left;
    Node* aux = leftChild->right;
    // Rotação
    leftChild->right = node;
    node->left = aux;

    // Atualiza altura
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    leftChild->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    return leftChild;
}

Node* AVLTree::insert(Node* node, int key) {
    if (node == nullptr) {
        Node* node = new Node();
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1; 
        return node;
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }

    // Atualiza a altura
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    // Verifica se está desbalanceado
    int balance = 0;
    if (node != NULL){
        balance = getHeight(node->left) - getHeight(node->right);
    }
    // Left Left Case
    if (balance > 1 && key < node->left->key){return rightRotate(node);}
    // Right Right Case
    if (balance < -1 && key > node->right->key){return leftRotate(node);}
    // Left Right Case
    if (balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (balance < -1 && key < node->right->key){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void AVLTree::print(Node *root)
{
    if(root != NULL)
    {
        cout << root->key << " ";
        print(root->left);
        print(root->right);
    }
}
void AVLTree::printTree(Node *node, int level)
{
    if (node == nullptr) {
        return;
    }
    printTree(node->right, level + 1);
    for (int i = 0; i < level; i++) {
        cout << "     " ;
    }
    cout << node->key << endl;
    printTree(node->left, level + 1);
}

int AVLTree::getHeight(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}