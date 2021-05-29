#include <iostream>
#define ll long long
using namespace std;

ll FirstIndex(ll arr[], ll n, ll x)
{

    ll low = 0, high = n - 1;
    while (low <= high)
    {
        ll mid = (low + high) / 2;

        if (arr[mid] > x)
        {
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
            {
                return mid;
            }
            else
            {
                high = mid - 1;
            }
        }
    }

    return -1;
}

ll LastIndex(ll arr[], ll n, ll x)
{
    ll low = 0, high = n - 1;
    while (low <= high)
    {

        ll mid = (low + high) / 2;

        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            if (arr[mid] == n - 1 || arr[mid + 1] != arr[mid])
                return mid;
            else
                low = mid + 1;
        }
    }

    return -1;
}

ll CountOccurrences(ll arr[], ll n, ll x)
{
    ll first = FirstIndex(arr, n, x);
    if (first == -1)
        return 0;
    else
        return (LastIndex(arr, n, x) - first + 1);
}
int main()
{
    ll arr[] = {1, 2, 3, 4, 5, 6, 8, 8, 9, 10};
    ll size = *(&arr + 1) - arr;
    ll x = 8;
    cout << CountOccurrences(arr, size, x) << endl;

    return 0;
}