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
    {
        temp = temp->next;
    }
    temp->next = NewNode;
}

void MergeTwoSortedLinkedList(Node *head1, Node *head2)
{
}

int main()
{
    Node *head1 = NULL;
    InsertAtTail(head1, 1);
    InsertAtTail(head1, 5);
    InsertAtTail(head1, 20);
    InsertAtTail(head1, 22);
    InsertAtTail(head1, 30);
    display(head1);

    Node *head2 = NULL;
    InsertAtTail(head2, 2);
    InsertAtTail(head2, 3);
    InsertAtTail(head2, 6);
    InsertAtTail(head2, 11);
    display(head2);

    return 0;
}