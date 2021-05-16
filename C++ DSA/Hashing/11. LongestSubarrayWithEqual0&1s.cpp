#include <iostream>
#include <unordered_map>
using namespace std;

int longestSub(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            arr[i] = -1;
    }
    unordered_map<int, int> m;
    int pre_sum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == 0)
            res = i + 1;
        if (m.find(pre_sum) == m.end())
            m.insert({pre_sum, i});
        if (m.find(pre_sum) != m.end())
            res = max(res, i - m[pre_sum]);
    }
    return res;
}

int main()
{
    int arr[] = {1, 1, 1, 0, 1, 0, 1, 1, 1};
    int n = *(&arr + 1) - arr;
    int sum = 4;

    cout << longestSub(arr, n) << endl;
    return 0;
}