// # Breadth First Traversal
#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

void bft(Node<int> *root)
{
    if (root == NULL)
        return;
    queue<Node<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        Node<int> *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

int main()
{
    Node<int> *root = new Node<int>(10);
    root->left = new Node<int>(20);
    root->right = new Node<int>(30);
    root->left->left = new Node<int>(40);
    bft(root);
    return 0;
}