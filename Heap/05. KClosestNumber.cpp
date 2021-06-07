#include <iostream>
#include <queue>
using namespace std;

void kClosest(int *arr, int n, int x, int k)
{
    priority_queue<pair<int, int>> maxh;
    for (int i = 0; i < n; i++)
    {
        maxh.push(make_pair(abs(arr[i] - x), arr[i]));

        if (maxh.size() > k)
            maxh.pop();
    }

    while (!maxh.empty())
    {
        cout << maxh.top().second << " ";
        maxh.pop();
    }
}

int main()
{
    int arr[] = {5, 6, 7, 8, 9};
    int n = *(&arr + 1) - arr;
    int x = 7, k = 3;
    kClosest(arr, n, x, k);
    return 0;
}