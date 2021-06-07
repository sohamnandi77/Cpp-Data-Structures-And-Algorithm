#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq = {10, 20, 30};
    dq.push_front(5);
    dq.push_back(50);
    for (auto x : dq)
        cout << x << " ";

    cout << endl;
    cout << dq.front() << " " << dq.back() << endl;

    return 0;
}