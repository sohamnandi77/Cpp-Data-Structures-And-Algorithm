#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int minNumOfCoins(int *arr, int n, int sum)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

    // * to get sum >= 0 from n=0 , we will be needing maximum no. of coins.
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 1; j <= sum; j++)
        dp[0][j] = INT_MAX - 1;

    // * Special Case: 2nd Row initialization
    for (int j = 1; j <= sum; j++)
        if (j % arr[0] == 0)
            dp[1][j] = j / arr[0];
        else
            dp[1][j] = INT_MAX - 1;

    // matrix
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= sum; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
            if (arr[i - 1] <= j)
                // # we used INT_MAX -1 because to prevent our code for making negative value when we add 1
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - arr[i - 1]]);
            else
                dp[i][j] = dp[i - 1][j];
    }

    if (dp[n][sum] == INT_MAX)
        return -1;

    return dp[n][sum];
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = *(&arr + 1) - arr;
    int sum = 7;
    cout << minNumOfCoins(arr, n, sum) << endl;
    return 0;
}