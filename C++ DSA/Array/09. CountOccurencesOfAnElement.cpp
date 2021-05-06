#include <iostream>
#define ll long long
using namespace std;
ll CountOccurrences(ll arr[], ll n, ll x)
{
    ll count = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        if (arr[i] == x)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    ll arr[] = {1, 2, 3, 4, 5, 6, 8, 8, 9, 10};
    ll size = *(&arr + 1) - arr;
    ll x = 8;
    cout << CountOccurrences(arr, size, x) << endl;

    return 0;
}