#include <iostream>
#define ll long long
using namespace std;

// Noob Method
ll searchNoob(ll arr[], ll x)
{
    ll i = 0;
    while (true)
    {
        if (arr[i] == x)
            return i;
        if (arr[i] > x)
            return -1;
        i++;
    }
}

//* OP Method
ll binarySearch(ll arr[], ll low, ll high, ll x)
{
    if (low > high)
        return -1;

    ll mid = (low + high) / 2;

    if (arr[mid] == x)
        return mid;

    else if (arr[mid] > x)
        return binarySearch(arr, low, mid - 1, x);

    else
        return binarySearch(arr, mid + 1, high, x);
}

ll searchOP(ll arr[], ll x)
{
    if (arr[0] == x)
        return 0;
    ll i = 1;
    while (arr[i] < x)
    {
        if (arr[i] == x)
            return i;
        i *= 2;
    }

    return binarySearch(arr, i / 2 + 1, i - 1, x);
}

int main()
{
    ll arr[] = {2, 8, 10, 12, 14, 18, 20, 22};
    ll x = 20;
    cout << searchNoob(arr, x);
    cout << endl;
    cout << searchOP(arr, x);

    return 0;
}