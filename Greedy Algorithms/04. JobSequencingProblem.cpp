#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int maxProfit(pair<int, int> *arr, int n)
{
    sort(arr, arr + n, compare);

    int mx = arr[0].first;
    // for (int i = 1; i < n; i++)
    //     mx = max(mx, arr[i].first);

    vector<int> res(n);          // to store the sequence of jobs
    vector<bool> slot(n, false); // to track if the slot if free or not

    int profit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].first) - 1; j >= 0; j--)
            if (!slot[j])
            {
                profit += arr[i].second;
                res[j] = i;
                slot[j] = true;
                break;
            }
    }

    // print the sequence in sorted array
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << res[i] << " ";
    cout << endl;
    return profit;
}

int main()
{
    pair<int, int> arr[] = {make_pair(2, 100),
                            make_pair(1, 19), make_pair(2, 27), make_pair(1, 25), make_pair(3, 15)};
    int n = *(&arr + 1) - arr;
    cout << maxProfit(arr, n) << endl;
    return 0;
}