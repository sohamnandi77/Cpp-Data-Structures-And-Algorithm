// ? Given a sorted array arr[] of size N without duplicates, and given a value x. Ceil of x is defined as the Smallest element K in arr[] such that K is greater than or equal to x. Find the index of K(0-based indexing).

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int findCeil(vector<long long> arr, long long n, long long x)
{

    ll low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        ll mid = high + (low - high) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            high = mid - 1;
            res = mid;
        }
    }
    return res;
}

int main()
{
    vector<long long> arr{1, 2, 8, 10, 11, 12, 19};
    long long n = 7;
    long long x = 3;
    cout << findCeil(arr, n, x) << endl;

    return 0;
}