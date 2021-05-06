#include <iostream>
#define ll long long
using namespace std;
ll secondSmallest(ll arr[], ll n)
{
    ll res = INT_MAX, smallest = 0;
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] < arr[smallest])
        {
            res = smallest;
            smallest = i;
        }
        else if (arr[i] != arr[smallest])
        {
            if (res == INT_MAX || arr[i] < arr[res])
                res = i;
        }
    }
    if (res == INT_MAX)
        res = -1;
    return res;
}

int main()
{
    ll arr[] = {-2, -1, -3, 10, 10};
    cout << secondSmallest(arr, 5) << endl;
    return 0;
}