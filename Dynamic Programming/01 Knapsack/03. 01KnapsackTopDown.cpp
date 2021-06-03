#include <iostream>
#include <vector>
using namespace std;

int knapsack01(int *weight, int *value, int n, int W)
{
    // # base case: --> Initialization
    // if (n == 0 || W == 0)
    //     return 0;

    // * initialize table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // -> we can skip it as we have initialized the complete dp with 0
    // for(int i = 0; i <= n; i++)
    //     dp[i][0] = 0;
    // for(int j = 0; j <= W; j++)
    //     dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (weight[i - 1] <= j)
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            else // if (weight[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
        }
    }

    // Matrix
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return dp[n][W];
}

int main()
{
    int weight[] = {1, 2, 3, 5};
    int value[] = {40, 20, 30, 100};
    int n = 4;
    int capacity = 7;
    cout << knapsack01(weight, value, n, capacity) << endl;
    return 0;
}