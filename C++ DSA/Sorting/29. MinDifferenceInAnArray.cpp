#include <iostream>
#include <algorithm>
using namespace std;

int minDiffNoob(int *arr, int n)
{
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            res = min(res, abs(arr[i] - arr[j]));
    return res;
}

int minDiffOP(int *arr, int n)
{
    sort(arr, arr + n);
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
        res = min(res, arr[i] - arr[i - 1]);
    return res;
}

int main()
{
    int arr[] = {5, 3, 8, 10, 12, 15};
    int n = *(&arr + 1) - arr;
    cout << minDiffNoob(arr, n) << endl;
    cout << minDiffOP(arr, n) << endl;
    return 0;
}
