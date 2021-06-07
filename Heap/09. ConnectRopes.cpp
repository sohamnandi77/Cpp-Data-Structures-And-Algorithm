#include <iostream>
#include <queue>
#define pq priority_queue<int, vector<int>, greater<int>>
using namespace std;

int minCost(int *arr, int n)
{
    int res = 0;
    pq maxh;
    for (int i = 0; i < n; i++)
        maxh.push(arr[i]);

    while (maxh.size() >= 2)
    {
        int x = maxh.top();
        maxh.pop();
        int y = maxh.top();
        maxh.pop();
        res += x + y;
        maxh.push(x + y);
    }

    return res;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = *(&arr + 1) - arr;
    cout << minCost(arr, n) << endl;
    return 0;
}