// ? Find the maximum difference between two elements such that j > i

#include <iostream>
using namespace std;

// Noob Method
int maxDiffNoob(int arr[], int n)
{
    int res = arr[1] - arr[0];

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            res = max(res, arr[j] - arr[i]);

    return res;
}

// OP Method
int maxDiffOP(int arr[], int n)
{
    int res = arr[1] - arr[0], minVal = arr[0];
    for (int j = 1; j < n; j++)
    {
        res = max(res, arr[j] - minVal);
        minVal = min(minVal, arr[j]);
    }
    return res;
}
int main()
{
    int arr[] = {2, 3, 10, 6, 4, 8, 1}, n = 7;
    cout << "Noob Solution" << endl;
    cout << maxDiffNoob(arr, n) << endl;
    cout << "OP Solution" << endl;
    cout << maxDiffOP(arr, n) << endl;
}