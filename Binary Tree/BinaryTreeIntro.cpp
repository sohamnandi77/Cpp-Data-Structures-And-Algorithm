#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

int main()
{
    Node<int> *root = new Node<int>(10);
    root->left = new Node<int>(20);
    root->right = new Node<int>(30);
    root->left->left = new Node<int>(40);
    return 0;
}