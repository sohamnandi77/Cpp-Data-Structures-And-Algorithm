// ? Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]].

#include <iostream>
#define ll long long
using namespace std;

void arrange(ll arr[], int n)
{
    for (ll i = 0; i < n; i++)
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
    ll arr[] = {4, 0, 2, 1, 3};
    ll size = *(&arr + 1) - arr;
    arrange(arr, size);
    for (ll x : arr)
    {
        cout << x << " ";
    }
    return 0;
}
