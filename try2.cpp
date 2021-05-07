// ? Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.

#include <iostream>
#define ll long long
using namespace std;

void arrange(ll arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] += (arr[arr[i]] % n) * n;
    }
    for (ll i = 0; i < n; i++)
    {
        arr[i] /= n;
    }
}

int main()
{
    ll arr[] = {1, 0};
    arrange(arr, 2);
    for (ll x : arr)
    {
        cout << x << " ";
    }
    return 0;
}
