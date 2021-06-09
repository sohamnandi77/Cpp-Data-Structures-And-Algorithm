#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return (double)(a.second / a.first) > (double)(b.second / b.first);
}

int fractionalKnapsack(int *wt, int *val, int n, int C)
{
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
        arr.push_back({wt[i], val[i]});

    sort(arr.begin(), arr.end(), compare);

    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].first <= C)
        {
            res += arr[i].second;
            C -= arr[i].first;
        }
        else
        {
            res += arr[i].second * ((double)C / arr[i].first);
            break;
        }
    }
    return res;
}

int main()
{
    int weight[] = {50, 20, 30};
    int value[] = {600, 500, 400};
    int n = *(&weight + 1) - weight;
    int capacity = 70;
    cout << fractionalKnapsack(weight, value, n, capacity) << endl;
    return 0;
}