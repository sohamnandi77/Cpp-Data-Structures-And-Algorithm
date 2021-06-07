#include <iostream>
#include <queue>
using namespace std;

int kLargest(int *arr, int n, int k)
{
    // Min Heap
    priority_queue<int, vector<int>, greater<int>> minh;
    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
            minh.pop();
    }

    return minh.top();
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = *(&arr + 1) - arr;
    int k = 3;
    cout << kLargest(arr, n, k) << endl;
    return 0;
}