#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

bool isSum(Node<int> *root)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return true;

    int sum = 0;
    if (root->left != NULL)
        sum += root->left->data;
    if (root->right != NULL)
        sum += root->right->data;

    return root->data == sum && isSum(root->left) && isSum(root->right);
}

int main()
{
    Node<int> *root = new Node<int>(20);
    root->left = new Node<int>(8);
    root->left->left = new Node<int>(3);
    root->left->right = new Node<int>(5);
    root->right = new Node<int>(12);
    cout << isSum(root) << endl;
    return 0;
}