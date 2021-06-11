// ? Problem : https://www.spoj.com/problems/AGGRCOW/

#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

bool isFeasible(int *arr, int n, int c, int min_sep)
{
    ll int last_cow = arr[0];
    ll int count = 1;
    for (ll i = 1; i < n; i++)
        if (arr[i] - last_cow >= min_sep)
        {
            last_cow = arr[i];
            count++;
            if (count == c)
                return true;
        }
    return false;
}

// # Think of the search space from 0 to N
ll int minMaxDistance(int *arr, int n, int c)
{
    ll int s = 0;
    ll int e = arr[n - 1] - arr[0];
    ll int ans = 0;
    while (s <= e)
    {
        ll int mid = e + (s - e) / 2;
        if (isFeasible(arr, n, c, mid))
        {
            s = mid + 1;
            ans = mid;
        }
        else
            e = mid - 1;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    ll int n, c;
    int arr[100000];

    while (t--)
    {
        cin >> n >> c;
        for (ll int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        sort(arr, arr + n);
        cout << minMaxDistance(arr, n, c) << endl;
    }

    return 0;
}