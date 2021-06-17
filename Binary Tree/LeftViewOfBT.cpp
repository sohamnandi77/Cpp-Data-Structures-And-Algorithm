#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

void leftView(Node<int> *root, int level)
{
    int maxLevel = 0;
    if (root == NULL)
        return;

    if (maxLevel < level)
    {
        cout << root->data << " ";
        maxLevel = level;
    }
    leftView(root->left, level + 1);
    leftView(root->right, level + 1);
}

void bft(Node<int> *root)
{
    if (root == NULL)
        return;
    queue<Node<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node<int> *curr = q.front();
            q.pop();
            if (i == 0)
                cout << curr->data << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}

int main()
{
    Node<int> *root = new Node<int>(30);
    root->right = new Node<int>(50);
    root->right->left = new Node<int>(60);
    root->right->left->right = new Node<int>(40);
    leftView(root, 1);
    cout << endl;
    bft(root);
    return 0;
}