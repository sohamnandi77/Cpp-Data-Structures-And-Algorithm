#include <iostream>
using namespace std;

// # The idea we use is that one half of the array is always sorted.

int minNumberNoob(int *arr, int low, int high) // # O(n) solution
{
    if (arr[high] > arr[low])
        return arr[low];
    while (arr[low] > arr[high])
    {
        high--;
    }
    return arr[high + 1];
}

int minNumberOP(int *arr, int low, int high) // # O(logN) solution
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < arr[mid - 1] || high == low)
            return arr[mid];
        else if (arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 40, 60, 5, 8}, n = 6;
    int x = 5;
    cout << minNumberNoob(arr, 0, n - 1) << endl;
    cout << minNumberOP(arr, 0, n - 1) << endl;

    return 0;
}