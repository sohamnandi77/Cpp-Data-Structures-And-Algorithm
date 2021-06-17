// # Breadth First Traversal
#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

int maxWidth(Node<int> *root)
{
    if (root == NULL)
        return 0;
    queue<Node<int> *> q;
    q.push(root);

    int res = INT_MIN;
    while (!q.empty())
    {
        int count = q.size();
        res = max(res, count);
        for (int i = 0; i < count; i++)
        {
            Node<int> *curr = q.front();
            q.pop();
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
    return res;
}

int main()
{
    Node<int> *root = new Node<int>(10);
    root->left = new Node<int>(20);
    root->right = new Node<int>(30);
    root->left->left = new Node<int>(40);
    cout << maxWidth(root) << endl;

    return 0;
}