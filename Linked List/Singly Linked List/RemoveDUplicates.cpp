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
        temp = temp->next;
    temp->next = NewNode;
}

void remDup(Node *&head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
            curr = curr->next;
    }
}

int main()
{
    Node *head = NULL;
    InsertAtTail(head, 1);
    InsertAtTail(head, 5);
    InsertAtTail(head, 20);
    InsertAtTail(head, 22);
    InsertAtTail(head, 30);
    display(head);

    remDup(head);
    display(head);

    return 0;
}