// # Breadth First Traversal
#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

void bft2(Node<int> *root)
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
            cout << curr->data << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }

        cout << endl;
    }
}

void bft(Node<int> *root)
{
    if (root == NULL)
        return;
    queue<Node<int> *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node<int> *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << endl;
            q.push(NULL);
            continue;
        }
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
    cout << endl;
    bft2(root);
    return 0;
}