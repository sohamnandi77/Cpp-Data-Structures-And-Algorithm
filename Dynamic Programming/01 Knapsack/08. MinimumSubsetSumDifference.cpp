#include <iostream>
#include <vector>
using namespace std;

int minSubsetDiff(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    vector<vector<bool>> matrix(n + 1, vector<bool>(sum + 1, true));
    for (int j = 1; j <= sum; j++)
        matrix[0][j] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
            if (arr[i - 1] <= j)
                matrix[i][j] = matrix[i - 1][j] || matrix[i - 1][j - arr[i - 1]];
            else
                matrix[i][j] = matrix[i - 1][j];
    }

    // only traversing the first half of last row of matrix
    for (int i = sum / 2; i >= 0; i--)
        if (matrix[n][i])
            return sum - 2 * i;

    return -1;
}

int main()
{
    int arr[] = {1, 2, 7};
    int n = *(&arr + 1) - arr;
    cout << minSubsetDiff(arr, n) << endl;
    return 0;
}