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

bool search(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return true;
        temp = temp->next; // act as iterator
    }
    return false;
}

int FindIndexIterative(Node *head, int key)
// * Time Complexity: O(n)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data == key)
            return count;
        temp = temp->next; // act as iterator
        count++;
    }
    return -1;
}

int FindIndexRecursive(Node *head, int key)
{
    if (head == NULL)
        return -1;
    if (head->data == key)
        return 1;
    else
    {
        int res = FindIndexRecursive(head->next, key);
        if (res == -1)
            return -1;
        else
            return res + 1;
    }
}

int main()
{

    Node *head = NULL;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtHead(head, 3);
    InsertAtHead(head, 4);
    display(head);
    cout << search(head, 3) << endl;
    cout << search(head, 7) << endl;
    cout << FindIndexIterative(head, 3) << endl;
    cout << FindIndexRecursive(head, 7) << endl;
    return 0;
}