#include <iostream>
#include <unordered_map>
#include <queue>
#include <math.h>
using namespace std;

void kClosestOrigin(pair<int, int> *arr, int n, int k)
{
    priority_queue<pair<int, pair<int, int>>> maxh;
    for (int i = 0; i < n; i++)
    {
        maxh.push({pow(arr[i].first, 2) + pow(arr[i].second, 2), {arr[i].first, arr[i].second}});
        if (maxh.size() > k)
            maxh.pop();
    }

    while (!maxh.empty())
    {
        cout << maxh.top().second.first << "," << maxh.top().second.second << " ";
        maxh.pop();
    }
}

int main()
{
    pair<int, int> arr[] = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int n = *(&arr + 1) - arr;
    int k = 2;
    kClosestOrigin(arr, n, k);
    return 0;
}