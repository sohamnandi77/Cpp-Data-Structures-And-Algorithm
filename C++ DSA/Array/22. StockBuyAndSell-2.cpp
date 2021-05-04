// ? Stock Buy & Sell to Maximise Profit - 2 - Leetcode 122
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve.You may complete as many transactions as youlike(i.e., buy one and sell one share of the stock multiple times).

#include <iostream>
#include <vector>
using namespace std;

// * Printing the range of transactions - Gfg
vector<vector<int>> stockBuySell(vector<int> price, int n)
{
    vector<vector<int>> res;

    if (n == 1)
        return res;

    int i = 0;

    while (i < n - 1)
    {
        // ? searching for maxima
        while (i < n - 1 && price[i + 1] <= price[i])
            i++;

        if (i == n - 1)
            break;

        int buy = i++;

        // ? searching for minima
        while (i < n && price[i] >= price[i - 1])
            i++;

        int sell = i - 1;
        res.push_back({buy, sell});
    }
    return res;
}

int maxProfitOP(int arr[], int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            profit += arr[i] - arr[i - 1];
        }
    }
    return profit;
}

int main()
{
    int arr[] = {1, 5, 3, 8, 12}, n = 5;
    cout << maxProfitOP(arr, n) << endl;
    vector<int> price{1, 5, 3, 8, 12};
    vector<vector<int>> ans = stockBuySell(price, n);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << "(" << ans[i][0] << " " << ans[i][1] << ") ";
    }
    return 0;
}