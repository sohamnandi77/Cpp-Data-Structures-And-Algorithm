// ? Problem : https://www.spoj.com/problems/EKO/

#include <iostream>
#define ll long long
using namespace std;
bool isFeasible(ll int *arr, ll int n, ll int m, ll int mid)
{
    ll int res = 0;
    for (ll int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            res += (arr[i] - mid);
    }
    if (res >= m)
        return true;
    return false;
}

ll int maxHeight(ll int *arr, ll int n, ll int m)
{
    ll int s = 0, e;
    for (ll int i = 1; i < n; i++)
        e = max(e, arr[i]);

    ll int ans = 0;
    while (s <= e)
    {
        ll int mid = e + (s - e) / 2;
        if (isFeasible(arr, n, m, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}

int main()
{
    ll int n, m;
    cin >> n >> m;
    ll int *arr = new ll int[n];
    for (ll int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxHeight(arr, n, m) << endl;
    delete[] arr;
    return 0;
}