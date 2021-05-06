#include <iostream>
#define ll long long
using namespace std;
ll isSorted(ll arr[], ll n)
{

    ll increase_sorted = 1;
    ll decrease_sorted = 1;

    for (ll i = 0; i < n; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            increase_sorted = 0;
            break;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (arr[i + 1] > arr[i])
        {
            decrease_sorted = 0;
            break;
        }
    }

    return increase_sorted || decrease_sorted;
}

int main()
{

    ll arr[4] = {4, 4, 4, 5};
    ll n = 4;
    cout << isSorted(arr, n);
    cout << endl;

    return 0;
}