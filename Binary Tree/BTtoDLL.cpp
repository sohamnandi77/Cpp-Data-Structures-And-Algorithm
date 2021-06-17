// # Breadth First Traversal
#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

Node<int> *BTToDLL(Node<int> *root)
{
    if (root == NULL)
        return root;
    static Node<int> *prev = NULL;
    Node<int> *head = BTToDLL(root->left);
    if (prev == NULL)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BTToDLL(root->right);
    return head;
}

void printlist(Node<int> *head)
{
    Node<int> *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main()
{
    Node<int> *root = new Node<int>(10);
    root->left = new Node<int>(5);
    root->right = new Node<int>(20);
    root->right->left = new Node<int>(30);
    root->right->right = new Node<int>(35);

    Node<int> *head = BTToDLL(root);
    printlist(head);
    return 0;
}