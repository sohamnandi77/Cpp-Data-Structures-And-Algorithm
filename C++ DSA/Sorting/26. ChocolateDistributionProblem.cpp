// ? Chocolate Distribution Problem

#include <iostream>
#include <algorithm>
using namespace std;

int minDiff(int *arr, int n, int m)
{
    if (m > n)
        return -1;
    sort(arr, arr + n);
    int res = arr[m - 1] - arr[0];
    for (int i = 0; m + i - 1 < n; i++)
        res = min(res, arr[i + m - 1] - arr[i]);
    return res;
}

void printMinDiff(int *arr, int n, int m)
{
    if (m > n)
        return;
    sort(arr, arr + n);
    int res = arr[m - 1] - arr[0];
    int start = 0, end = m - 1;
    for (int i = 0; m + i - 1 < n; i++)
        if (res > (arr[i + m - 1] - arr[i]))
        {
            res = arr[i + m - 1] - arr[i];
            start = i;
            end = i + m - 1;
        }
    for (int i = start; i <= end; i++)
        cout << arr[i] << " ";
}

int main()
{
    int arr[] = {5, 13, 6, 9, 12, 11, 8};
    int n = *(&arr + 1) - arr;
    int k = 3;
    cout << minDiff(arr, n, k) << endl;
    printMinDiff(arr, n, k);
    return 0;
}