// Find the Maximum of all subarrays of size k

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void maxKNOOB(int *arr, int n, int k)
// # Time Complexity: O(n^2)
{
    for (int i = 0; i <= n - k; i++)
    {
        int res = INT_MIN;
        for (int j = 0; j < k; j++)
            res = max(res, arr[i + j]);
        cout << res << " ";
    }
    return;
}

void maxKOP(int *arr, int n, int k)
// # Time Complexity: O(n)
{
    if (k > n)
    {
        cout << *max_element(arr, arr + n) << endl;
        return;
    }
    deque<int> q;
    int i = 0, j = 0;
    while (j < n)
    {
        // calculations
        while (!q.empty() && q.back() < arr[j])
            q.pop_back();
        q.push_back(arr[j]);

        if (j - i + 1 < k)
            j++;

        if (j - i + 1 == k)
        {
            // calculating ans
            cout << q.front() << " ";

            // sliding the window
            if (arr[i] == q.front())
                q.pop_front();
            i++;
            j++;
        }
    }
    return;
}

int main()
{
    int arr[] = {1, 3, -1, 5, 3, 6, 7};
    int size = *(&arr + 1) - arr;
    maxKNOOB(arr, size, 3);
    cout << endl;
    maxKOP(arr, size, 3);
    return 0;
}