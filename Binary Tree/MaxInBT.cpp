#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

int maxBT(Node<int> *root)
{

    if (root == NULL)
        return INT_MIN;

    return max(root->data, max(maxBT(root->left), maxBT(root->right)));
}

int main()
{
    Node<int> *root = new Node<int>(10);
    root->left = new Node<int>(20);
    root->right = new Node<int>(30);
    root->left->left = new Node<int>(40);
    cout << maxBT(root) << endl;
    return 0;
}