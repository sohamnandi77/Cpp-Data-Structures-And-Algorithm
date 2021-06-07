#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// # Iterative
void reverse(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

// # Recursive

void reverse(queue<int> &q)
{
    if (q.empty())
        return;

    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    reverse(q);

    // print the queue
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}