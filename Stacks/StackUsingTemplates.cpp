#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class StackUsingArray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingArray()
    {
        capacity = 4;
        T *data = new T[capacity];
        nextIndex = 0;
    }

    // return the number of elements present in my stacks
    int size() { return nextIndex; }

    // is empty or not
    bool isEmpty() { return nextIndex == 0; }

    // insert element
    void push(T element)
    {
        if (nextIndex == capacity)
        {
            T *NewData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
                NewData[i] = data[i];
        }

        data[nextIndex++] = element;
    }

    // delete Element
    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    // top element
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        return data[nextIndex - 1];
    }
};
int main()
{
    StackUsingArray<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.isEmpty() << endl;
    return 0;
}