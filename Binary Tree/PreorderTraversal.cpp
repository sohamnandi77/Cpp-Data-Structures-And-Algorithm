#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

void preorder(Node<int> *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    Node<int> *root = new Node<int>(10);
    root->left = new Node<int>(20);
    root->right = new Node<int>(30);
    root->left->left = new Node<int>(40);
    preorder(root);
    return 0;
}