#include <iostream>
#include <vector>
using namespace std;

// * 0/1 knapsack similarities
// # arr[] -> weight[]
// # sum -> W

bool isSubset(int *arr, int n, int sum)
{

    // base case:
    // if (n == 0 && sum > 0)
    //     return false;
    // if (n >= 0 && sum == 0)
    //     return true;

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

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int n = *(&arr + 1) - arr;
    int sum = 11;
    cout << isSubset(arr, n, sum) << endl;
    return 0;
}