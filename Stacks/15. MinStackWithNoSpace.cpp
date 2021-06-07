#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
stack<int> s1;
int minEle;
int getMin()
{
    if (s1.empty())
        return -1;

    return minEle;
}

void push(int x)
{
    if (s.empty())
        s.push(x);
    else
    {
        if (x >= minEle)
            s.push(x);
        else if (x < minEle)
        {
            s.push(2 * x - minEle); //* flag
            minEle = x;
        }
    }

    return;
}

void pop()
{
    if (s.empty())
        return;
    else if (s.top() >= minEle)
        s.pop();
    else if (s.top() < minEle)
    {
        minEle = 2 * minEle - s.top();
        s.pop();
    }
}

int top()
{
    if (s.empty())
        return -1;
    else if (s.top() >= minEle)
        return s.top();
    else if (s.top() < minEle)
        return minEle;
}

int main()
{
    int arr[] = {18, 19, 29, 15, 16};
    int n = *(&arr + 1) - arr;
    return 0;
}