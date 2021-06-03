#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int LPS(string x, int m)
{
    // # Just reverse the string to convert the questio from LCS to LPS
    string y = x;
    reverse(y.begin(), y.end());
    int n = y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // recursive case:
    // # if last string matchs, exclude the last letter of both
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

    return dp[m][n];
}

int main()
{
    string x = "agbcba";
    cout << LPS(x, x.length()) << endl;

    return 0;
}