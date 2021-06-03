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
    if (head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);

    // * Another method
    // while (temp->next != head)
    // {
    //     cout << temp->data << "->";
    //     temp = temp->next;
    // }
    // cout << temp->data << endl;
}

Node *InsertAtBegin(Node *&head, int val)
{
    Node *NewNode = new Node(val);
    if (head == NULL)
    {
        NewNode->next = NewNode;
        // head = NewNode;
        return NewNode;
    }
    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = temp;
    temp->next = head;
    // head = NewNode;
    return NewNode;
}

int main()
{
    Node *head = NULL;
    InsertAtBegin(head, 2);
    InsertAtBegin(head, 1);
    display(head);
    return 0;
}