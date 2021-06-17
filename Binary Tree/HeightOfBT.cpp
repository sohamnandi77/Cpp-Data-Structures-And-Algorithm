#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

int heightBT(Node<int> *root)
{

    if (root == NULL)
        return 0;

    return max(heightBT(root->left), heightBT(root->right)) + 1;
}

int main()
{
    Node<int> *root = new Node<int>(10);
    root->left = new Node<int>(20);
    root->right = new Node<int>(30);
    root->left->left = new Node<int>(40);
    cout << heightBT(root) << endl;
    return 0;
}