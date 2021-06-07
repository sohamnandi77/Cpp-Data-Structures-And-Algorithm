#include <iostream>
#include <queue>
using namespace std;

int kSmallest(int *arr, int n, int k)
{
    // Max Heap
    priority_queue<int> maxh;
    for (int i = 0; i < n; i++)
    {
        maxh.push(arr[i]);
        if (maxh.size() > k)
            maxh.pop();
    }

    return maxh.top();
}

int sumBtwK1K2(int *arr, int n, int k1, int k2)
{
    int s1 = kSmallest(arr, n, k1);
    int s2 = kSmallest(arr, n, k2);
    int res = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > s1 && arr[i] < s2)
            res += arr[i];
    return res;
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = *(&arr + 1) - arr;
    int k1 = 2, k2 = 5;
    cout << sumBtwK1K2(arr, n, k1, k2) << endl;
    return 0;
}