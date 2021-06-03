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

void InsertAtHead(Node *&head, int val)
// * Time Complexity: O(1)
{
    Node *NewNode = new Node(val);
    if (head == NULL)
    {
        head = NewNode;
        return;
    }
    NewNode->next = head; // first point newNode to head
    head = NewNode;       // then change the head
    return;
}

void display(Node *head) //* pass the display function by value so that it i not able to make changes to the head pointer
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
    InsertAtHead(head, 5);
    InsertAtHead(head, 6);
    display(head);
    return 0;
}