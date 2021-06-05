#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

Node *InsertAtBegin(Node *head, int val)
{
    Node *NewNode = new Node(val);
    if (head == NULL)
    {
        head = NewNode;
        return head;
    }

    NewNode->next = head;
    head->prev = NewNode;
    head = NewNode;
    return head;
}

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

int main()
{
    Node *head = NULL;
    head = InsertAtBegin(head, 5);
    head = InsertAtBegin(head, 6);
    display(head);
    return 0;
}