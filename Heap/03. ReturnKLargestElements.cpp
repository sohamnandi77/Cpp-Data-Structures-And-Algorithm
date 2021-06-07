#include <iostream>
#include <queue>
#define pq priority_queue<int, vector<int>, greater<int>>

using namespace std;

pq kLargest(int *arr, int n, int k)
{
    // Max Heap
    pq minh;
    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
            minh.pop();
    }
    return minh;
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = *(&arr + 1) - arr;
    int k = 3;
    pq h = kLargest(arr, n, k);
    while (!h.empty())
    {
        cout << h.top() << endl;
        h.pop();
    }
    return 0;
}