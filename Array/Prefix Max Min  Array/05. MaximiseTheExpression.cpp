// # Problem:  https://codeforces.com/problemset/problem/855/B
// ? maximize the expression: p*arr[i] + q*arr[j] + r*arr[k], where i < j < k

#include <iostream>
using namespace std;

int maximize(int arr[], int n, int p, int q, int r)
{
    // # To skip making two arrays, you can initialize pmax to INT_MIN and update it in the core logic

    //-> prefix max
    // int *pmax = new int[n];
    // pmax[0] = p * arr[0];
    // for (int i = 1; i <= n - 1; i++)
    //     pmax[i] = max(pmax[i - 1], p * arr[i]);

    //-> suffix max
    int *smax = new int[n];
    smax[n - 1] = r * arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        smax[i] = max(smax[i + 1], r * arr[i]);

    int res = INT_MIN, pmax = INT_MIN;
    for (int i = 1; i <= n - 2; i++)
    {
        pmax = max(pmax, p * arr[i - 1]);
        res = max(res, pmax + q * arr[i] + smax[i + 1]);
    }

    delete[] smax;
    return res;
}

// ? maximize the expression: p*arr[i] + q*arr[j] + r*arr[k], where i <= j <= k
int maximize2(int arr[], int n, int p, int q, int r)
{
    // # To skip making two arrays, you can initialize pmax to INT_MIN and update it in the core logic
    // -> prefix max
    // int *pmax = new int[n];
    // pmax[0] = p * arr[0];
    // for (int i = 1; i <= n - 1; i++)
    //     pmax[i] = max(pmax[i - 1], p * arr[i]);

    // -> suffix max
    int *smax = new int[n];
    smax[n - 1] = r * arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        smax[i] = max(smax[i + 1], r * arr[i]);

    int res = INT_MIN, pmax = INT_MIN;
    for (int i = 0; i <= n - 1; i++)
    {
        pmax = max(pmax, p * arr[i]);
        res = max(res, pmax + q * arr[i] + smax[i]);
    }

    delete[] smax;
    return res;
}

int main()
{
    int arr[] = {-1, -2, -3, -4, -5};
    int n = *(&arr + 1) - arr;
    int p = 1, q = 2, r = -3;
    cout << maximize(arr, n, p, q, r) << endl;
    cout << maximize2(arr, n, p, q, r) << endl;
    return 0;
}