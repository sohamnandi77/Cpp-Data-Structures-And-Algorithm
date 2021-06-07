#include <iostream>
#include <unordered_map>
#include <queue>
#define pq priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
using namespace std;

void topKFreq(int *arr, int n, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    pq minh;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        minh.push({i->second, i->first});
        if (minh.size() > k)
            minh.pop();
    }

    while (!minh.empty())
    {
        cout << minh.top().second << " ";
        minh.pop();
    }
}

int main()
{
    int arr[] = {1, 1, 3, 2, 2, 2, 4, 4};
    int n = *(&arr + 1) - arr;
    int k = 2;
    topKFreq(arr, n, k);
    return 0;
}