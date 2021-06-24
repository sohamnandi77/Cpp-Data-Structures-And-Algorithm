#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;

void print(ll int num, ll int &N, ll int &K, vector<ll int> &res)
{
    ll int num1 = stoi(to_string(num) + '4');
    if (num1 % K == 0 && num1 <= N)
        res.push_back(num1);

    ll int num2 = stoi(to_string(num) + '5');
    if (num2 % K == 0 && num2 <= N)
        res.push_back(num2);

    ll int num3 = stoi(to_string(num) + '6');
    if (num3 % K == 0 && num3 <= N)
        res.push_back(num3);

    if (num1 <= N && num2 <= N && num3 <= N)
    {
        print(num1, N, K, res);
        print(num2, N, K, res);
        print(num3, N, K, res);
    }
}

int main()
{
    ll int n, k;
    cin >> n >> k;
    vector<ll int> res;
    if (n >= k && n >= 4 && k > 1)
        print(0, n, k, res);
    sort(res.begin(), res.end());
    for (int x : res)
        cout << x << " ";

    return 0;
}