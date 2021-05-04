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

void DeleteAtHead(Node *&head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    head = head->next;
    delete temp;
}

void InsertAtHead(Node *&head, int val)
{
    Node *NewNode = new Node(val);
    NewNode->next = head;
    head = NewNode;
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
    InsertAtHead(head, 0);
    InsertAtHead(head, 1);
    display(head);
    DeleteAtHead(head);
    display(head);
    return 0;
}