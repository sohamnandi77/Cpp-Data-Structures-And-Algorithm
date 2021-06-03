#include <iostream>
#include <vector>
using namespace std;

int knapsack01_2D(int *weight, int *prices, int n, int W)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            // # only diff between 01 knapsack & unbounded knapsack is when we include or process the item then we do
            // -> dp[i-1][j-weight[i-1]] => 01 Knapsack
            // -> dp[i][j-weight[i-1]] => Unbounded knapsack
            if (weight[i - 1] <= j)
                dp[i][j] = max(prices[i - 1] + dp[i][j - weight[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}

int knapsack01_1D(int *weight, int *value, int n, int W) // 1D DP
{
    vector<int> dp(W + 1, 0);
    for (int i = 0; i <= W; i++)
        for (int j = 0; j <= n; j++)
            if (weight[j] <= i)
                dp[i] = max(dp[i], dp[i - weight[j]] + value[j]);

    return dp[W];
}

int main()
{
    int weight[] = {5, 10, 15};
    int prices[] = {10, 30, 20};
    int n = *(&weight + 1) - weight;
    int capacity = 100;
    cout << knapsack01_1D(weight, prices, n, capacity) << endl;
    cout << knapsack01_2D(weight, prices, n, capacity) << endl;
    return 0;
}