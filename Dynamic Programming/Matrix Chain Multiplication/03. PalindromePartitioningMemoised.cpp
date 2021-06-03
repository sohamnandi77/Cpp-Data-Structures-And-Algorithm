#include <iostream>
#include <vector>
using namespace std;

bool isPal(string &str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int palPartition(string &s, int i, int j)
{
    // Base Case:
    // already a palindrome
    if (i >= j)
        return 0;

    // check if the string is palindrom or not for zero partition
    // ? if we move the isPal fun after the above step then we don't need optimization step
    if (isPal(s, i, j))
        return 0;

    vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int left, right;

        // dp[i][j] = palPartition(s, i, k) + palPartition(s, k + 1, j) + 1;

        // ans = min(ans, dp[i][j]);

        // # optimization for above
        if (dp[i][k] != -1)
            left = dp[i][k];
        else
            left = palPartition(s, i, k);

        if (dp[k + 1][j] != -1)
            right = dp[k + 1][j];
        else
            right = palPartition(s, k + 1, j);

        dp[i][j] = 1 + left + right;
        ans = min(ans, dp[i][j]);
    }

    return dp[i][j] = ans;
}

int main()
{
    string s = "ababbbabbababa";
    int n = s.length();
    cout << palPartition(s, 0, n - 1) << endl;
    return 0;
}