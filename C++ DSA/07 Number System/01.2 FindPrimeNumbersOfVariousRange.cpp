// ? Find Prime Number in Range

#include <iostream>
#include <numeric>
#include <vector>
#define ll long long
using namespace std;

vector<ll int> PrimeSieve(ll int n)
{
    vector<ll int> arr(n, 1);

    // Special Cases
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;

    for (ll int i = 4; i <= n; i += 2)
        arr[i] = 0;

    for (ll int i = 3; i * i <= n; i += 2)
        if (arr[i] == 1)
            for (ll int j = i * i; j <= n; j += i)
                arr[j] = 0;

    // prefix Count
    partial_sum(arr.begin(), arr.end(), arr.begin());

    return arr;
}

ll int FindPrimeInRange(vector<ll int> &arr, ll l, ll r)
{
    return arr[r] - arr[l];
}

int main()
{
    ll int n = 100;
    vector<ll int> arr = PrimeSieve(n);
    ll int l = 1, r = 10;
    cout << FindPrimeInRange(arr, l, r) << endl;
    return 0;
}