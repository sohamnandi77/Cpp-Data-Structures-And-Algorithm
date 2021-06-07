#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

void topKFreq(int *arr, int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    priority_queue<pair<int, int>> maxh;
    for (auto i = mp.begin(); i != mp.end(); i++)
        maxh.push({i->second, i->first});

    while (!maxh.empty())
    {
        for (int i = 0; i < maxh.top().first; i++)
            cout << maxh.top().second << " ";
        maxh.pop();
    }
}

int main()
{
    int arr[] = {1, 1, 3, 2, 2, 2, 4, 4};
    int n = *(&arr + 1) - arr;
    topKFreq(arr, n);
    return 0;
}