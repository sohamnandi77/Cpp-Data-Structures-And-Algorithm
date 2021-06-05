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

void InsertNode(Node *&head, int i, int val)
{

    // Base Case
    if (head == NULL || i < 0)
        return;

    // If the List is NULL
    if (i == 0)
    {
        Node *NewNode = new Node(val);
        NewNode->next = head;
        head = NewNode;
        return;
    }

    // Recursive
    InsertNode(head->next, i - 1, val);
}

int main()
{
    Node *head = NULL;
    InsertNode(head, 0, 0);
    display(head);
    return 0;
}