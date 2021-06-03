#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

int main()
{
    // Statically
    Node n1(1);
    Node *head = &n1;

    Node n2(2);
    n1.next = &n2;
    n2.prev = &n1;

    cout << head->data << endl;

    cout << "NULL<-" << n1.data << "<->" << n2.data << "->NULL" << endl;

    // Dynamically
    Node *n3 = new Node(10);
    Node *head2 = n3;
    Node *n4 = new Node(20);
    n3->next = n4;
    n4->prev = n3;

    cout << "NULL<-" << n3->data << "<->" << n4->data << "->NULL" << endl;
    return 0;
}