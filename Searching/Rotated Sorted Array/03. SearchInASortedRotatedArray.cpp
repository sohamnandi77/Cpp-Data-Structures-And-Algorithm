#include <iostream>
#define ll long long
using namespace std;

// # The idea we use is that one half of the array is always sorted.

ll search(ll arr[], ll n, ll x)
{

    ll low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        ll mid = low + ((high - low) / 2);

        if (arr[mid] == x)
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid;
            else
                high = mid - 1;
        }

        //* Left Half Sorted
        if (arr[low] < arr[mid])
        {
            if (x >= arr[low] && x < arr[mid]) //* arr[low] <= x < arr[mid] should not be done
                high = mid - 1;
            else
                low = mid + 1;
        }

        //* Right Half Sorted
        else
        {
            if (x > arr[mid] && x <= arr[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    ll arr[] = {10, 20, 40, 60, 5, 5, 8};
    ll n = *(&arr + 1) - arr;
    ll x = 5;

    cout << search(arr, n, x);

    return 0;
}