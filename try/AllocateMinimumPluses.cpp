#include <iostream>
#include <string>
using namespace std;

int sum(string str, int b, int e)
{
    int s = 0;
    for (int i = b; i < e; i++)
        s += str[i];
    return s;
}

int minPluses(string str, int n, int k)
{
    if (k == stoi(str))
        return 0;
    if (n == 1)
        return -1;
    int res = INT_MAX;

    for (int i = 1; i < n; i++)
        res = min(res, max(minPluses(str, i, k - 1), sum(str, i, n - 1)));

    return res;
}

int main()
{
    string str = "550";
    int k = 10;
    cout << minPluses(str, str.length(), k) << endl;
    return 0;
}