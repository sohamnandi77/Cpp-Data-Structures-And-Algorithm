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
        this->next = NULL;
    }
};
void InsertAtHead(Node *&head, int val)
{
    Node *NewNode = new Node(val);
    NewNode->next = head;
    head = NewNode;
}
void InsertAtTail(Node *&head, int val)
{
    Node *NewNode = new Node(val);
    if (head == NULL)
    {
        InsertAtHead(head, val);
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NewNode;
}

void display(Node *head)
{
    //? Don't Directly work on head node as we will loose the address of head node and won't be able to print it again.
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int Length(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
int main()
{
    Node *head = NULL;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtHead(head, 3);
    InsertAtHead(head, 4);
    display(head);
    cout << Length(head) << endl;
    return 0;
}