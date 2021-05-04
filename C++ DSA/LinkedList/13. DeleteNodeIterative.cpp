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
void print(Node *head)
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

Node *DeleteNode(Node *head, int i)
{
    if (i == 0)
    {
        head = head->next;
        return head;
    }
    int count = 0;
    Node *temp = head;
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        Node *a = temp->next;
        temp->next = temp->next->next;
        delete a;
    }
    return head;
}

Node *takeInputImproved()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
            // or
            // tail = newNode;
        }
        cin >> data;
    }
    return head;
}
int main()
{
    Node *head = takeInputImproved();
    print(head);
    head = DeleteNode(head, 2);
    print(head);
    return 0;
}