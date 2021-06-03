#include <iostream>
#include <vector>
using namespace std;

bool isSubset(int *arr, int n, int sum)
{

    //* initialization --> same as base case
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
    return matrix[n][sum];
}

bool equalSum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 == 0) //even
        return isSubset(arr, n, sum / 2);

    return false; // odd
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int n = *(&arr + 1) - arr;
    cout << equalSum(arr, n) << endl;
    return 0;
}