// Find the maximum sum of k consecutive elements

#include <iostream>
using namespace std;

int maxKsumNOOB(int *arr, int n, int k)
{
    int maxSum = INT_MIN;
    for (int i = 0; i + k - 1 < n; i++)
    {
        int res = 0;
        for (int j = 0; j < k; j++)
        {
            res += arr[i + j];
        }
        maxSum = max(maxSum, res);
    }
    return maxSum;
}

// * Window Sliding Technique
int maxKsumOP(int *arr, int n, int k)
{
    int currSum = 0;
    for (int i = 0; i < k; i++)
    {
        currSum += arr[i];
    }
    int maxSum = currSum;
    for (int i = k; i < n; i++)
    {
        currSum += (arr[i] - arr[i - k]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main()
{
    int arr[] = {1, 8, 30, -5, 20, 7};
    int size = *(&arr + 1) - arr;
    cout << maxKsumNOOB(arr, size, 3) << endl;
    cout << maxKsumOP(arr, size, 3) << endl;
    return 0;
}