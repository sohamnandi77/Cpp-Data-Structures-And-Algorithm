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

Node *ReverseIterative(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node *Reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *rest_head = Reverse(head->next);
    Node *rest_tail = head->next;
    // Node *temp = rest_head;
    // while (temp->next != NULL)
    //     temp = temp->next;
    // temp->next = head;
    rest_tail->next = head;
    head->next = NULL;
    return rest_head;
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

    // head = ReverseIterative(head);
    head = Reverse(head);
    display(head);

    return 0;
}