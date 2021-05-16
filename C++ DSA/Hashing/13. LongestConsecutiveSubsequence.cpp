#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int longestSub(int *arr, int n)
{
    sort(arr, arr + n);
    int res = 1, curr = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
            curr++;
        else if (arr[i] != arr[i - 1])
        {
            res = max(res, curr);
            curr = 1;
        }
    }
    return res;
}

int longestSubOP(int *arr, int n)
// * Time Complexity: O(n)
// * Aux Space: O(n)
// ? There are always 2n lookups
{
    unordered_set<int> s(arr, arr + n);
    int res = 1;
    for (int x : s)
    {
        if (s.find(x - 1) != s.end())
        {
            int curr = 1;
            while (s.find(x + curr) != s.end())
                curr++;
            res = max(res, curr);
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 9, 3, 4, 2, 10, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestSub(arr, n);
    return 0;
}