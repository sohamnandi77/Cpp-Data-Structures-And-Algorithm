#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class Stack
{
    Node<T> *head;
    int size; //number of elements present in stack

public:
    Stack()
    {
        head = NULL;
        size = 0;
    }

    int getSize() { return size; }

    bool isEmpty() { return size == 0; } // or head == NULL;

    void push(T element)
    {
        Node<T> *NewNode = new Node<T>(element);
        NewNode->next = head;
        head = NewNode;
        size++;
    }

    T pop()
    {
        if (isEmpty())
            return 0;
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return ans;
    }

    T top()
    {
        if (isEmpty())
            return 0;
        return head->data;
    }
};

int main()
{
    Stack<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.getSize() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}