#include <iostream>
#include <algorithm>
using namespace std;

bool mycomp(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }

void mergeIntervals(pair<int, int> arr[], int n)
{
    sort(arr, arr + n, mycomp);
    int res = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[res].second >= arr[i].first)
        {
            arr[res].second = max(arr[res].second, arr[i].second);
            arr[res].first = min(arr[res].first, arr[i].first);
        }
        else
        {
            res++;
            arr[res] = arr[i];
        }
    }

    for (int i = 0; i <= res; i++)
        cout << "[" << arr[i].first << ", " << arr[i].second << "] ";
}

int main()
{
    pair<int, int> arr[] = {{5, 10}, {3, 15}, {18, 30}, {2, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);

    return 0;
}
