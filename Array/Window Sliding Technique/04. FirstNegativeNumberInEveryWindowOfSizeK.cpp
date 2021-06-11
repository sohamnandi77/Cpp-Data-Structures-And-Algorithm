#include <iostream>
#include <queue>
using namespace std;

void FirstNegativeNumberNoob(int *arr, int n, int k)
// # Time Complexity: O(n^2)
{
    for (int i = 0; i <= n - k; i++)
    {
        bool flag = false;
        for (int j = i; j < i + k; j++)
        {
            if (arr[j] < 0)
            {
                cout << arr[j] << " ";
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << 0 << " ";
    }

    return;
}

void FirstNegativeNumberOP(int *arr, int n, int k)
// # Time Complexity: O(n)
{
    queue<int> q;

    int j = 0;
    int i = 0;
    while (j < n && i < n)
    {
        // Calculations
        if (arr[j] < 0)
            q.push(arr[j]);

        if (j - i + 1 < k)
            j++;

        else if (j - i + 1 == k)
        {
            // Calculating Answer
            if (q.empty())
                cout << 0 << " ";
            else
                cout << q.front() << " ";

            // Slide the Window
            if (arr[i] == q.front())
                q.pop();

            i++;
            j++;
        }
    }
    return;
}

int main()
{
    int arr[] = {12, -1, -7, 8, -18, 30, 13, 28};
    int n = *(&arr + 1) - arr;
    int k = 3;
    FirstNegativeNumberNoob(arr, n, k);
    return 0;
}