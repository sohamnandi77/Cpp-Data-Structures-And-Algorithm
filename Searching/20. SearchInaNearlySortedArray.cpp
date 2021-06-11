#include <iostream>
#define ll long long
using namespace std;

ll binarySearch(ll arr[], ll n, ll x)
{
    ll low = 0;
    ll high = n - 1;
    while (low <= high)
    {
        ll mid = high + (low - high) / 2;

        if (mid - 1 >= low && arr[mid - 1] == x)
            return mid - 1;

        else if (arr[mid] == x)
            return mid;

        else if (mid + 1 <= high && arr[mid + 1] == x)
            return mid + 1;

        else if (arr[mid] > x)
            high = mid - 2;

        else
            low = mid + 2;
    }

    return -1;
}

int main()
{
    ll arr[] = {10, 3, 40, 20, 50, 80, 70};
    ll size = *(&arr + 1) - arr;
    ll x = 40;

    cout << binarySearch(arr, size, x) << endl;

    return 0;
}