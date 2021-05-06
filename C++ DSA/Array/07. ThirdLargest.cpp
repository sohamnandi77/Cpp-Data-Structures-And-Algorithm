#include <iostream>
# define ll long long
using namespace std;
ll ThirdLargest(ll a[], ll n)
{
    ll first = a[0], second = INT_MIN, third = INT_MIN;
    for (ll i = 1; i < n; i++)
    {
        if (a[i] > first)
        {
            third = second;
            second = first;
            first = a[i];
        }
        else if (a[i] > second && a[i] != first)
        {
            third = second;
            second = a[i];
        }
        else if (a[i] > third && a[i] != second && a[i] != first)
        {
            third = a[i];
        }
    }
    if (third == INT_MIN)
        third = -1;
    return third;
}
int main()
{
    ll arr[] = {20, 10, 2, 20, 10};
    cout << ThirdLargest(arr, 5) << endl;
    return 0;
}