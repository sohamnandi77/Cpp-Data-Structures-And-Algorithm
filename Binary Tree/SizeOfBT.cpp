#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

int sizeBT(Node<int> *root)
{

    if (root == NULL)
        return 0;

    return sizeBT(root->left) + sizeBT(root->right) + 1; //? adding 1 for the root node
}

int main()
{
    Node<int> *root = new Node<int>(10);
    root->left = new Node<int>(20);
    root->right = new Node<int>(30);
    root->left->left = new Node<int>(40);
    cout << sizeBT(root) << endl;
    return 0;
}