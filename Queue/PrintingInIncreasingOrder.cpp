#include <iostream>
#include <string>
#include <queue>
#define ll long long
using namespace std;

// String Number Comparision
bool com(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    if (n != m)
        return n > m;
    for (int i = 0; i < n; i++)
        if ((s1[i] - '0') < (s2[i] - '0'))
            return false;
    return true;
}

// Function to compute num (mod a)
int mod(string num, int a)
{
    // Initialize result
    int res = 0;

    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + (int)num[i] - '0') % a;

    return res;
}

void printFirstN(ll int n, ll int k)
{
    queue<string> q;
    q.push("4");
    q.push("5");
    q.push("6");
    while (!com(q.front(), to_string(n)))
    {
        string curr = q.front();
        if (mod(curr, k) == 0) //# how to check a mod of very large number
            cout << curr << " ";
        q.pop();
        q.push(curr + "4");
        q.push(curr + "5");
        q.push(curr + "6");
    }
}

int main()
{
    ll int n = 10000000000000;
    ll int k = 787;
    if (n >= k && n >= 4)
        printFirstN(n, k);
    return 0;
}