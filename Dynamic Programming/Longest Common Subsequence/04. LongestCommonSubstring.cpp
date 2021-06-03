#include <iostream>
#include <string>
#include <vector>
using namespace std;

int LCS(string x, string y, int m, int n)
{
    int result = 0;
    // base case:
    if (m == 0 || n == 0)
        return 0;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // recursive case:
    // # if last string matchs, exclude the last letter of both
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                result = max(result, dp[i][j]);
            }
            else
                dp[i][j] = 0;

    return result;
}

int main()
{
    string x = "abcdghli";
    string y = "abcdfhil";
    cout << LCS(x, y, x.length(), y.length()) << endl;
    return 0;
}