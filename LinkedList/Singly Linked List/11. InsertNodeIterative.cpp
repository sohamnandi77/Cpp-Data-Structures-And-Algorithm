#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void InsertNode(Node *&head, int i, int val)
{
    // if invalid i
    if (i < 0)
        return;

    Node *NewNode = new Node(val);

    // If the List is NULL
    if (i == 0)
    {
        NewNode->next = head;
        head = NewNode;
        return;
    }

    int count = 0;
    Node *temp = head;
    while (temp != NULL && count < i - 1) // stop at i-2 th node
    {
        temp = temp->next;
        count++;
    }

    // if i is out of bound -> simply return the original list
    if (temp == NULL)
        return;

    // if i is not out of bound and within the length of the list
    if (temp != NULL)
    {
        NewNode->next = temp->next;
        temp->next = NewNode; //! Don't write this statement before the above statement as then we might loose the address of ith node.
        return;
    }
}
int main()
{
    Node *head = NULL;
    InsertNode(head, 0, 0);
    InsertNode(head, 1, 1);
    InsertNode(head, 2, 2);
    InsertNode(head, 4, 4);
    display(head);
    return 0;
}