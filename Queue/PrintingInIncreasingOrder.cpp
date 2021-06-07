#include <iostream>
#include <string>
#include <queue>
#define ll long long
using namespace std;

void printFirstN(ll int n, ll int k)
{
    queue<string> q;
    q.push("4");
    q.push("5");
    q.push("6");
    while (stoi(q.front()) < n)
    {
        string curr = q.front();
        if (stoi(curr) % k == 0) //# how to check a mode of very large number
            cout << curr << " ";
        q.pop();
        q.push(curr + "4");
        q.push(curr + "5");
        q.push(curr + "6");
    }
}

int main()
{
    ll int n = 10000000000;
    ll int k = 256564;
    if (n >= k && n >= 4)
        printFirstN(n, k);
    return 0;
}