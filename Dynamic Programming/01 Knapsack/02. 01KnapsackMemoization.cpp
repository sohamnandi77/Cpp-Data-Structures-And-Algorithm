#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int matrix[100][100]; // n*c matrix according to constraints

int knapsack01(int *weight, int *prices, int n, int c)
{
    // base case:
    if (n == 0 || c == 0)
        return 0;

    // memoization
    if (matrix[n][c] != -1)
        return matrix[n][c];

    // recursive case:
    int inc = 0, exc = 0;

    if (weight[n - 1] <= c)
    {
        inc = prices[n - 1] + knapsack01(weight, prices, n - 1, c - weight[n - 1]);
        exc = knapsack01(weight, prices, n - 1, c);
        matrix[n][c] = max(inc, exc);
        return matrix[n][c];
    }
    else if (weight[n - 1] > c)
    {
        matrix[n][c] = knapsack01(weight, prices, n - 1, c);
        return matrix[n][c];
    }

    return 0;
}

int main()
{
    memset(matrix, -1, 100 * 100 * sizeof(int));
    int weight[] = {1, 2, 3, 5};
    int prices[] = {40, 20, 30, 100};
    int n = 4;
    int capacity = 7;
    cout << knapsack01(weight, prices, n, capacity) << endl;
    return 0;
}