#include <iostream>
#include <vector>
using namespace std;

int countSubset(int *arr, int n, int sum)
{
    vector<vector<int>> matrix(n + 1, vector<int>(sum + 1, 1));
    for (int j = 1; j <= sum; j++)
        matrix[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
            if (arr[i - 1] <= j)
                matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j - arr[i - 1]];
            else
                matrix[i][j] = matrix[i - 1][j];
    }
    return matrix[n][sum];
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int n = *(&arr + 1) - arr;
    int sum = 10;
    cout << countSubset(arr, n, sum) << endl;
    return 0;
}