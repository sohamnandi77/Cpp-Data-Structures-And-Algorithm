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

int NthNode(Node *head, int x)
{
    if (head == NULL)
        return -1;
    Node *fast = head;
    int curr = 1;
    while (fast != NULL && curr < x)
    {
        fast = fast->next;
        curr++;
    }
    if (curr != x)
        return -1;
    Node *slow = head;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
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

    cout << NthNode(head, 2) << endl;
    display(head);

    return 0;
}