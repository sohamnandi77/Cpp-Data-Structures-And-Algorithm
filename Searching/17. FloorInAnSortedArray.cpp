// ? Given a sorted array arr[] of size N without duplicates, and given a value x. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. Find the index of K(0-based indexing).

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int findFloor(vector<long long> arr, long long n, long long x)
{

    // Your code here
    ll low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        ll mid = high + (low - high) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > x)
            high = mid - 1;
        else
        {
            low = mid + 1;
            res = mid;
        }
    }
    return res;
}

int main()
{
    vector<long long> arr{1, 2, 8, 10, 11, 12, 19};
    long long n = 7;
    long long x = 0;
    cout << findFloor(arr, n, x) << endl;

    return 0;
}