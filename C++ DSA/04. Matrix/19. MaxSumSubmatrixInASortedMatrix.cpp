#include <iostream>
using namespace std;

int maxSumSubmatrix(int **arr, int n, int m)
{
    // * Suffix Matrix
    // Col wise Addition
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 2; j >= 0; j--)
            arr[i][j] += arr[i][j + 1];

    // Row wise Addition
    for (int i = m - 2; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            arr[i][j] += arr[i + 1][j];

    int res = INT_MIN;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res = max(res, arr[i][j]);
    return res;
}

int main()
{
    int m = 3, n = 3;
    int mat[3][3] = {{-5, -4, -1}, {-3, 2, 4}, {2, 5, 8}};
    int **arr = new int *[m];
    for (int i = 0; i < m; i++)
        arr[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = mat[i][j];

    cout << maxSumSubmatrix(arr, n, m) << endl;

    //* deallocation of memory
    for (int i = 0; i < m; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}