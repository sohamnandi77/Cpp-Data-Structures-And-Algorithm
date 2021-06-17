#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

int heightBT(Node<int> *root)
{

    if (root == NULL)
        return 0;

    return max(heightBT(root->left), heightBT(root->right)) + 1;
}

bool isBalancedNoob(Node<int> *root)
{
    if (root == NULL)
        return 0;

    return abs(heightBT(root->left) - heightBT(root->right)) < 2 && isBalancedNoob(root->left) && isBalancedNoob(root->right);
}

int isBalanced(Node<int> *root)
{
    if (root == NULL)
        return 0;
    int lh = isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return max(lh, rh) + 1;
}

int main()
{
    Node<int> *root = new Node<int>(10);
    root->left = new Node<int>(20);
    root->right = new Node<int>(30);
    root->left->left = new Node<int>(40);
    cout << isBalancedNoob(root) << endl;
    cout << isBalanced(root) << endl;
    return 0;
}