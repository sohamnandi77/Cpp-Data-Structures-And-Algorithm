#include <iostream>
#include <algorithm>
using namespace std;

const int R = 3, C = 3;

int medianNoob(int arr[R][C])
// * Time Complexity: O(rc log(rc))
{
    int x = 0;
    int *a = new int[R * C];
    int n = R * C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            a[x++] = arr[i][j];
    sort(a, a + n);
    if (n % 2 == 0)
        return (int)a[n / 2];
    else
        return (int)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
    delete[] a;
}

int medianOP(int arr[R][C])
// * Time Complexity: O(r log(max-min)logC)
{
    int mn = arr[0][0], mx = arr[0][C - 1];
    for (int i = 1; i < R; i++)
    {
        mn = min(arr[i][0], mn);
        mx = max(arr[i][C - 1], mx);
    }
    int medPos = (R * C + 1) / 2;
    while (mn < mx)
    {
        int mid = mn + (mx - mn) / 2;
        int midPos = 0;
        for (int i = 0; i < R; i++)
            midPos += upper_bound(arr[i], arr[i] + C, mid) - arr[i];
        if (midPos < medPos)
            mn = mid + 1;
        else
            mx = mid;
    }
    return mn;
}

void print(int arr[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // print(arr);
    cout << medianOP(arr) << endl;
    cout << medianNoob(arr) << endl;
    return 0;
}