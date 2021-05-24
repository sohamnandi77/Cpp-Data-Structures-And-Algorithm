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
    // base case
    if (temp == NULL)
    {
        cout << "NULL" << endl;
        return;
    }
    cout << temp->data << "->";
    display(temp->next);
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
    return 0;
}