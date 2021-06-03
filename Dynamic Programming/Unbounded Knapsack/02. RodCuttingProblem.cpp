#include <iostream>
#include <vector>
using namespace std;

// # Matching rod cutting with 01 knapsack
// * W => L (max Length or size of array)
// * value => price
// * weight => length

int rodCutting(int *prices, int *length, int n, int L)
{
    vector<vector<int>> dp(n + 1, vector<int>(L + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= L; j++)
        {
            if (length[i - 1] <= j)
                dp[i][j] = max(prices[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][L];
}

int main()
{
    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int length[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = *(&prices + 1) - prices;
    int max_length = n;
    cout << rodCutting(prices, length, n, max_length) << endl;
    return 0;
}