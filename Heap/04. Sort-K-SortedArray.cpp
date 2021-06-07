#include <iostream>
#include <queue>
#define pq priority_queue<int, vector<int>, greater<int>>
using namespace std;

void kSorted(int *arr, int n, int k)
{
    pq minh;
    for (int i = 0; i < n; i++)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
        {
            cout << minh.top() << " ";
            minh.pop();
        }
    }

    while (!minh.empty())
    {
        cout << minh.top() << " ";
        minh.pop();
    }
}

int main()
{
    int arr[] = {6, 5, 3, 2, 8, 10, 9};
    int n = *(&arr + 1) - arr;
    int k = 3;
    kSorted(arr, n, k);
    return 0;
}