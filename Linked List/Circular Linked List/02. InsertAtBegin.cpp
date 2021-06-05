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

Node *InsertAtBeginNoob(Node *&head, int val)
// # Time Complexity: O(n)
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

    temp->next = NewNode;
    NewNode->next = head;
    // head = NewNode;
    return NewNode;
}

Node *InsertAtBeginOP(Node *&head, int val)
// # Time Complexity: O(n)
{
    Node *NewNode = new Node(val);
    if (head == NULL)
    {
        NewNode->next = NewNode;
        // head = NewNode;
        return NewNode;
    }
    // Insert teh node after the First Node
    NewNode->next = head->next;
    head->next = NewNode;
    int temp = head->data;
    head->data = NewNode->data;
    NewNode->data = temp;
    return head;
}

int main()
{
    Node *head = NULL;
    head = InsertAtBeginNoob(head, 1);
    head = InsertAtBeginNoob(head, 2);
    head = InsertAtBeginOP(head, 3);
    head = InsertAtBeginOP(head, 4);
    display(head);
    return 0;
}