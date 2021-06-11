#include <iostream>
#define ll long long
using namespace std;

ll sum(ll *arr, ll b, ll e)
{
    ll s = 0;
    for (ll i = b; i <= e; i++)
        s += arr[i];
    return s;
}

ll minPagesNoob(ll arr[], ll n, ll k)
{
    if (k == 1)
        return sum(arr, 0, n - 1);
    if (n == 1)
        return arr[0];
    ll res = INT_MAX;

    for (ll i = 1; i < n; i++)
        res = min(res, max(minPagesNoob(arr, i, k - 1), sum(arr, i, n - 1)));

    return res;
}

bool isFeasible(ll arr[], ll n, ll k, ll ans)
{
    ll students = 1;
    ll current_pages = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > ans)
            return false;
        if ((current_pages + arr[i]) > ans)
        {
            current_pages = arr[i];
            students++;
            if (students > k)
                return false;
        }
        else
            current_pages += arr[i];
    }
    return true;
}

ll minPagesOP(ll *arr, ll n, ll k)
{
    ll totalPages = 0, start = 0, end = 0, res = start;
    for (ll i = 0; i < n; i++)
    {
        totalPages += arr[i];
        start = max(start, arr[i]);
    }
    end = totalPages;
    while (start <= end)
    {
        ll mid = end + (start - end) / 2;
        if (isFeasible(arr, n, k, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return res;
}

int main()
{
    ll arr[] = {10, 20, 10, 30};
    ll n = *(&arr + 1) - arr;
    ll k = 2;
    cout << minPagesNoob(arr, n, k) << endl;
    cout << minPagesOP(arr, n, k) << endl;
    return 0;
}