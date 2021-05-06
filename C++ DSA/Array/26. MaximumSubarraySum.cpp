#include <iostream>
using namespace std;

// NOOB Method
int maxSumNoob(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += arr[j];
            res = max(res, curr);
        }
    }
    return res;
}

//* OP Method - Kadane's Algorithm

int maxSumOP(int arr[], int n)
{
    int maxEnding = arr[0], res = arr[0];
    for (int i = 1; i < n; i++)
    {
        maxEnding = max((maxEnding + arr[i]), arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

int main()
{
    int arr[] = {1, -2, 3, -1, 2}, n = 5;
    cout << "OP Method" << endl;
    cout << maxSumOP(arr, n) << endl;
    cout << "NOOB Method" << endl;
    cout << maxSumNoob(arr, n) << endl;
    return 0;
}