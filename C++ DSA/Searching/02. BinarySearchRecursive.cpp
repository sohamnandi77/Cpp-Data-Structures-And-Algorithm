#include <iostream>
#define ll long long
using namespace std;

// ? Iterative Binary Search is better than Recursive Binary Search as it avoids unncessary function overheads and also saves function call stack memory

ll binarySearch(ll arr[], ll low, ll high, ll x)
{
    if (low > high)
        return -1;

    ll mid = high + (low - high) / 2;

    if (arr[mid] == x)
        return mid;

    else if (arr[mid] > x)
        return binarySearch(arr, low, mid - 1, x);

    else
        return binarySearch(arr, mid + 1, high, x);
}
int main()
{
    ll arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ll x = 4;
    ll size = *(&arr + 1) - arr;
    cout << binarySearch(arr, 0, size - 1, x) << endl;

    return 0;
}