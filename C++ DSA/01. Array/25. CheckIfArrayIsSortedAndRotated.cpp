// ? Given an array arr[] of N distinct integers, check if this array is Sorted (non-increasing or non-decreasing) and Rotated counter-clockwise. Note that input array may be sorted in either increasing or decreasing order, then rotated.
// ? A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation.

#include <iostream>
using namespace std;
bool isIncSorted(int arr[], int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}
bool isDecSorted(int arr[], int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i] > arr[i - 1])
            return false;
    }
    return true;
}

bool checkRotatedAndSorted(int arr[], int n)
{

    int min_idx = 0, max_idx = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[max_idx] < arr[i])
            max_idx = i;
        if (arr[min_idx] > arr[i])
            min_idx = i;
    }
    // Decreasing sorted and rotated
    if (min_idx == max_idx - 1)
    {
        if (arr[n - 1] < arr[0])
            return false;
        if (!isDecSorted(arr, max_idx, n - 1))
            return false;
        if (!isDecSorted(arr, 0, min_idx))
            return false;
        return true;
    }
    // Increasing sorted and rotated
    else if (max_idx == min_idx - 1)
    {
        if (arr[n - 1] > arr[0])
            return false;
        if (!isIncSorted(arr, min_idx, n - 1))
            return false;
        if (!isIncSorted(arr, 0, max_idx))
            return false;
        return true;
    }
    return false;
}
int main()
{
    int arr[] = {3, 4, 1, 2};
    int size = *(&arr + 1) - arr;
    cout << checkRotatedAndSorted(arr, size) << endl;
    return 0;
}