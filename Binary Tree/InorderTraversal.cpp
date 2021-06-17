#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

void inorder(Node<int> *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node<int> *root = new Node<int>(10);
    root->left = new Node<int>(20);
    root->right = new Node<int>(30);
    root->left->left = new Node<int>(40);
    inorder(root);
    return 0;
}