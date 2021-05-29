#include <iostream>
#include <vector>
using namespace std;

int knapsack01(int *weight, int *prices, int n, int c)
{
    // base case:
    if (n == 0 || c == 0)
        return 0;

    // recursive case:
    int inc = 0, exc = 0;
    // if we include the last item
    if (weight[n - 1] <= c)
        inc = prices[n - 1] + knapsack01(weight, prices, n - 1, c - weight[n - 1]);

    // if we exclude the last item
    exc = knapsack01(weight, prices, n - 1, c);
    return max(inc, exc);
}

int main()
{
    int weight[] = {1, 2, 3, 5};
    int prices[] = {40, 20, 30, 100};
    int n = 4;
    int capacity = 7;
    cout << knapsack01(weight, prices, n, capacity) << endl;
    return 0;
}