#include <iostream>
#include <climits>
using namespace std;

class StackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        capacity = 4;
        data = new int[capacity];
        nextIndex = 0;
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
            int *NewData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
                NewData[i] = data[i];
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
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}