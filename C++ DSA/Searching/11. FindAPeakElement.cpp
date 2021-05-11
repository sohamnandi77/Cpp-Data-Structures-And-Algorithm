#include <iostream>
#define ll long long
using namespace std;

ll getPeak(ll arr[], ll n)
{
    ll low = 0, high = n - 1;
    while (low <= high)
    {
        ll mid = high + (low - high) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
            return mid;
        if (mid > 0 && arr[mid - 1] >= arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    ll arr[] = {5, 20, 40, 30, 20, 50, 60}, n = 7;
    cout << getPeak(arr, n) << endl;
    return 0;
}