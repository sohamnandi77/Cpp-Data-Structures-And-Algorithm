#include <iostream>
#define ll long long
using namespace std;

// Noob Solution
ll getWaterNoob(ll arr[], ll n)
{
    ll res = 0;

    for (ll i = 1; i < n - 1; i++)
    {
        ll lMax = arr[i];

        for (ll j = 0; j < i; j++)
            lMax = max(lMax, arr[j]);

        ll rMax = arr[i];

        for (ll j = i + 1; j < n; j++)
            rMax = max(rMax, arr[j]);

        res += (min(lMax, rMax) - arr[i]);
    }

    return res;
}

// Space Solution

ll getWaterSpace(ll arr[], ll n)
{
    ll res = 0;
    ll *lMax = new ll[n];
    ll *rMax = new ll[n];

    // left array
    lMax[0] = arr[0];
    for (ll i = 1; i < n; i++)
        lMax[i] = max(arr[i], lMax[i - 1]);

    // right array
    rMax[n - 1] = arr[n - 1];
    for (ll i = n - 2; i >= 0; i--)
        rMax[i] = max(arr[i], rMax[i + 1]);

    // Water stored
    for (ll i = 1; i < n - 1; i++)
        res = res + (min(lMax[i], rMax[i]) - arr[i]);

    delete[] lMax, rMax;
    return res;
}

// OP Solution -  Two Pointer Approach

ll getWaterOP(ll arr[], ll n)
{
    ll res = 0, l = 0, r = n - 1, lMax = 0, rMax = 0;

    while (l <= r)
    {
        if (arr[l] <= arr[r])
        {
            if (arr[l] > lMax)
                lMax = arr[l];
            else
                res += lMax - arr[l];
            l++;
        }
        else
        {
            if (arr[r] > rMax)
                rMax = arr[r];
            else
                res += rMax - arr[r];
            r--;
        }
    }
    return res;
}

int main()
{

    ll arr[] = {3, 0, 1, 2, 5}, n = 5;

    cout << "Noob Solution" << endl;
    cout << getWaterNoob(arr, n) << endl;
    cout << "Space Solution" << endl;
    cout << getWaterSpace(arr, n) << endl;
    cout << "OP Solution" << endl;
    cout << getWaterOP(arr, n) << endl;
}