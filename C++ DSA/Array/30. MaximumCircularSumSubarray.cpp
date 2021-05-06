#include <iostream>
using namespace std;
int maxSum(int *arr, int size)
{
    int maxEnding = arr[0], res = arr[0];
    for (int i = 1; i < size; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int maxCircularSum(int *arr, int n)
{
    int maxNormal = maxSum(arr, n);

    // * this is important as if all the elements are negative, then circularSum will result in 0 which is incorrect
    if (maxNormal < 0)
        return maxNormal;

    int arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
        arr[i] = -arr[i];
    }

    int circularSum = arrSum + maxSum(arr, n);
    return max(circularSum, maxNormal);
}

int main()
{
    int arr[] = {8, -4, 3, -5, 4}, n = 5;
    cout << maxCircularSum(arr, n) << endl;
    return 0;
}