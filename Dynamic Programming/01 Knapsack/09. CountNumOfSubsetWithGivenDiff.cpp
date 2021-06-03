// # Another variantion of this problem is Target Sum problem: https://leetcode.com/problems/target-sum/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int countSubsetWithDiff(int *arr, int n, int diff)
{

    int count0 = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] == 0)
            count0++;
    }
    if (diff > sum)
        return 0;
    // # When sum(arr) + diff is an odd number, then there won't exist any subset like that and we can return zero from there itself.
    if ((diff + sum) % 2 != 0)
        return 0;

    int s = (diff + sum) / 2;

    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 1));
    for (int j = 1; j <= s; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (arr[i - 1] == 0)
                dp[i][j] = dp[i - 1][j];
            else if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    //-> A special case for every case of zero. -> just multiply the answer with pow(2,count0) to consider every permutation of 0.
    return pow(2, count0) * dp[n][s];
}

int main()
{
    int arr[] = {1, 1, 2, 0, 3};
    int n = *(&arr + 1) - arr;
    int diff = 1;
    cout << countSubsetWithDiff(arr, n, diff) << endl;
    return 0;
}