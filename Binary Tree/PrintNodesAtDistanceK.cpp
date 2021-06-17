#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

void printNodes(Node<int> *root, int k)
{
    if (root == NULL)
        return;

    //? Base Case:
    if (k == 0)
        cout << root->data << endl;
    else
    {
        printNodes(root->left, k - 1);
        printNodes(root->right, k - 1);
    }
}

int main()
{
    Node<int> *root = new Node<int>(10);
    root->left = new Node<int>(20);
    root->right = new Node<int>(30);
    root->left->left = new Node<int>(40);
    printNodes(root, 1);
    return 0;
}