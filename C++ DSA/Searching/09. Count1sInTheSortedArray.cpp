#include <iostream>
#define ll long long
using namespace std;
ll Count1s(ll arr[], ll n)
{
    ll low = 0, high = n - 1;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        if (arr[mid] == 0)
            low = mid + 1;
        else
        {
            if (mid == 0 || arr[mid - 1] == 0)
                return n - mid;
            else
                high = mid - 1;
        }
    }
    return 0;
}
int main()
{
    ll arr[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    ll size = *(&arr + 1) - arr;
    cout << Count1s(arr, size) << endl;
    return 0;
}