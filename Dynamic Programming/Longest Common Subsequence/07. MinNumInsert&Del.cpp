#include <iostream>
#include <string>
#include <vector>
using namespace std;

pair<int, int> LCS(string x, string y, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // recursive case:
    // # if last string matchs, exclude the last letter of both
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

    int LCS = dp[m][n];
    int numDel = m - LCS;
    int numInsert = n - LCS;
    return make_pair(numDel, numInsert);
}

int main()
{
    string x = "abcdghli";
    string y = "abedfhil";
    pair<int, int> res = LCS(x, y, x.length(), y.length());
    cout << "No of Insertions: " << res.first << endl;
    cout << "No of Deletions: " << res.second << endl;
    return 0;
}