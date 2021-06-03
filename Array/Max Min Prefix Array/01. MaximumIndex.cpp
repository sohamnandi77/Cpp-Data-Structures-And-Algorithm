// ? Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].

#include <iostream>
using namespace std;
int maxIndexDiff(int arr[], int n)
// # Time Complexity: O(n)
// # Space Complexity: O(n)
{

    int *left = new int[n];
    int *right = new int[n];
    int min_idx, max_idx;
    min_idx = left[0] = arr[0];
    max_idx = right[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min_idx)
            min_idx = arr[i];
        left[i] = min_idx;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max_idx)
            max_idx = arr[i];
        right[i] = max_idx;
    }
    int maxDiff = INT_MIN, i = 0, j = 0;
    while (i < n && j < n)
    {
        if (left[i] <= right[j])
        {
            maxDiff = max(maxDiff, j - i);
            j++;
        }
        else
            i++;
    }
    delete[] left, right;
    return maxDiff;
}
int main()
{
    int arr[] = {34, 8, 10, 3, 2, 80, 30, 33, 1};
    int size = *(&arr + 1) - arr;
    cout << maxIndexDiff(arr, size) << endl;
    return 0;
}