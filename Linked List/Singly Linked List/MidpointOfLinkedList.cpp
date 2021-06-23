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

int MidPoint(Node *head)
{
    if (head == NULL)
        return -1;
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main()
{
    Node *head = NULL;
    InsertAtTail(head, 0);
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    // InsertAtTail(head, 4);
    display(head);
    cout << MidPoint(head) << endl;
    return 0;
}