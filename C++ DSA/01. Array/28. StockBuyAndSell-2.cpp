// ? Stock Buy & Sell to Maximise Profit - 2 - Leetcode 122
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve.You may complete as many transactions as youlike(i.e., buy one and sell one share of the stock multiple times).

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

// * Printing the range of transactions - Gfg
vector<vector<ll>> stockBuySell(vector<ll> price, ll n)
{
    vector<vector<ll>> res;

    if (n == 1)
        return res;

    ll i = 0;

    while (i < n - 1)
    {
        // ? searching for maxima
        while (i < n - 1 && price[i + 1] <= price[i])
            i++;

        if (i == n - 1)
            break;

        ll buy = i++;

        // ? searching for minima
        while (i < n && price[i] >= price[i - 1])
            i++;

        ll sell = i - 1;
        res.push_back({buy, sell});
    }
    return res;
}

ll maxProfitOP(ll arr[], ll n)
{
    ll profit = 0;
    for (ll i = 1; i < n; i++)
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
    ll arr[] = {1, 5, 3, 8, 12}, n = 5;
    cout << maxProfitOP(arr, n) << endl;
    vector<ll> price{1, 5, 3, 8, 12};
    vector<vector<ll>> ans = stockBuySell(price, n);
    for (ll i = 0; i < ans.size(); ++i)
    {
        cout << "(" << ans[i][0] << " " << ans[i][1] << ") ";
    }
    return 0;
}