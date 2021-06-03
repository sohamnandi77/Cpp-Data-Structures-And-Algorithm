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

void DeleteAtTail(Node *&head)
// * Time Complexity: O(n)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        delete head;
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    // Delete Last Node
    delete temp->next;

    // Change next of second last
    temp->next = NULL;
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
    DeleteAtTail(head);
    display(head);
    return 0;
}