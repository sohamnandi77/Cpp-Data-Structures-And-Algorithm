#include <iostream>
#define ll long long
using namespace std;

// ? Iterative Binary Search is better than Recursive Binary Search as it avoids unncessary function overheads and also saves function call stack memory

ll binarySearch(ll arr[], ll n, ll x)
{
    ll low = 0;
    ll high = n - 1;
    while (low <= high)
    {
        ll mid = high + (low - high) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > x)
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    ll arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ll x = 4;
    ll size = *(&arr + 1) - arr;

    cout << binarySearch(arr, size, x) << endl;

    return 0;
}