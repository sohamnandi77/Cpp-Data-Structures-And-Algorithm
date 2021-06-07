#include <iostream>
#include <deque>
using namespace std;

void printMaxK_Noob(int *arr, int n, int k)
{
    for (int i = 0; i < n - k + 1; i++)
    {
        int mx = arr[i];
        for (int j = i; j < i + k; j++)
            mx = max(mx, arr[j]);
        cout << mx << " ";
    }
}

void printMaxK_OP(int arr[], int n, int k)
{

    deque<int> dq;

    for (int i = 0; i < k; ++i)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    for (int i = k; i < n; ++i)
    {

        cout << arr[dq.front()] << " ";

        while ((!dq.empty()) && dq.front() <= i - k)
            dq.pop_front();

        while ((!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[dq.front()];
}

int main()
{
    int arr[] = {10, 8, 5, 12, 15, 7, 6};
    int n = *(&arr + 1) - arr;
    int k = 3;
    printMaxK_Noob(arr, n, k);
    cout << endl;
    printMaxK_OP(arr, n, k);
    return 0;
}