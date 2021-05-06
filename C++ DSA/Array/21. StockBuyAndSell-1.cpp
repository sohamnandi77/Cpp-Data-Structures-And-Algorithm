// ? Stock Buy & Sell to Maximise Profit - Leetcode 121
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction.If you cannot achieve any profit, return 0.

// * this problem is very similar to maximum Difference Problem

#include <iostream>
using namespace std;
int maxProfitNoob(int arr[], int n)
{
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int curr_profit = arr[j] - arr[i];
            profit = max(profit, curr_profit);
        }
    }
    return profit;
}

int maxProfitSpace(int arr[], int n)
{
    int profit = 0;
    int *aux = new int[n];
    int curr_max = arr[n - 1];
    aux[n - 1] = curr_max;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= curr_max)
        {
            aux[i] = arr[i];
            curr_max = arr[i];
        }
        else
        {
            aux[i] = curr_max;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int curr_max = aux[i] - arr[i];
        profit = max(profit, curr_max);
    }

    delete[] aux;
    return profit;
}

int maxProfitOP(int arr[], int n)
{
    int min_so_far = arr[0];
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        min_so_far = min(min_so_far, arr[i]);
        int curr_profit = arr[i] - min_so_far;
        profit = max(profit, curr_profit);
    }
    return profit;
}

int main()
{
    int arr[] = {12, 5, 9, 8, 1}, n = 5;
    cout << maxProfitNoob(arr, n) << endl;
    cout << maxProfitSpace(arr, n) << endl;
    cout << maxProfitOP(arr, n) << endl;
    return 0;
}