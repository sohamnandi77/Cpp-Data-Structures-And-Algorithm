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
    //? Don't Directly work on head node as we will loose the address of head node and won't be able to print it again.
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
    // Statically
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    Node *head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    display(head);
    display(head);

    // Dynamically
    Node *d1 = new Node(10);
    Node *d2 = new Node(20);
    Node *d3 = new Node(30);
    Node *d4 = new Node(40);
    Node *d5 = new Node(50);

    Node *head2 = d1;
    d1->next = d2;
    d2->next = d3;
    d3->next = d4;
    d4->next = d5;

    display(head2);

    return 0;
}
