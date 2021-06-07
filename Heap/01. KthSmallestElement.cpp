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

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = *(&arr + 1) - arr;
    int k = 3;
    cout << kSmallest(arr, n, k) << endl;
    return 0;
}