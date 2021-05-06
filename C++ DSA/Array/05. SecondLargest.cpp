#include <iostream>
#define ll long long
using namespace std;
ll secondLargest(ll arr[], ll n)
{
    ll res = INT_MIN, largest = 0;
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] > arr[largest])
        {
            res = largest;
            largest = i;
        }
        else if (arr[i] != arr[largest])
        {

            if (res == INT_MIN || arr[i] > arr[res])
                res = i;
        }
    }
    if (res == INT_MIN)
        res = -1;
    return res;
}
int main()
{
    ll arr[] = {5, 10, -2, 8, 10};
    cout << secondLargest(arr, 5) << endl;
    return 0;
}
