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

Node *InsertAtEnd(Node *&head, int val)
{
    Node *NewNode = new Node(val);

    // If Linked List is Empty
    if (head == NULL)
    {
        head = NewNode;
        return head;
    }

    int count = 0;
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = NewNode;
    NewNode->prev = temp;

    return head;
}

Node *Reverse(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    // if more than two items
    Node *temp = head, *prev = NULL;
    while (temp != NULL)
    {
        prev = temp->prev;
        temp->prev = temp->next;
        temp->next = prev;
        temp = temp->prev;
        cout << prev << endl;
    }

    head = prev->prev;
    return head;
}

void display(Node *head)
{

    Node *temp = head;
    cout << "NULL<-";
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
    head = InsertAtBegin(head, 1);
    head = InsertAtBegin(head, 2);
    head = InsertAtEnd(head, 3);
    head = InsertAtEnd(head, 4);
    display(head);
    head = Reverse(head);
    display(head);
    return 0;
}