#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    // return the number of elements present in my stacks
    int size() { return nextIndex; }

    // is empty or not
    bool isEmpty() { return nextIndex == 0; }

    // insert element
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        data[nextIndex++] = element;
    }

    // delete Element
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // top element
    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
};
int main()
{
    StackUsingArray s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);                  // stack overflow
    cout << s.top() << endl;     // 40
    cout << s.pop() << endl;     // 40
    cout << s.pop() << endl;     // 30
    cout << s.pop() << endl;     // 20
    cout << s.size() << endl;    // 1
    cout << s.isEmpty() << endl; // false
    return 0;
}