#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
stack<int> s1;
int getMin()
{
    if (s1.empty())
        return -1;

    return s1.top();
}

void push(int a)
{

    s.push(a);
    if (s.empty() || s1.top() >= a) // # equality is important
        s1.push(a);

    return;
}
int pop()
{
    if (s.empty())
        return -1;

    int ans = s.top();
    s.pop();
    if (s1.top() == ans)
        s1.pop();

    return ans;
}

int main()
{
    int arr[] = {18, 19, 29, 15, 16};
    int n = *(&arr + 1) - arr;
    return 0;
}