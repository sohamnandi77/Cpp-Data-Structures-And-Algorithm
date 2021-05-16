#include <iostream>
#include <unordered_map>
using namespace std;

int maxLenNoob(int *arr, int n, int sum)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];
            if (curr_sum == sum)
                res = max(res, j - i + 1);
        }
    }
    return res;
}

int maxLenOP(int *arr, int n, int sum)
{
    unordered_map<int, int> m;
    int pre_sum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == sum)
            res = i + 1;
        if (m.find(pre_sum) == m.end())
            m.insert({pre_sum, i});
        if (m.find(pre_sum - sum) != m.end())
            res = max(res, i - m[pre_sum - sum]);
    }
    return res;
}

int main()
{
    int arr[] = {8, 3, 1, 5, 6, -6, 2, 2};
    int n = *(&arr + 1) - arr;
    int sum = 4;

    cout << maxLenNoob(arr, n, sum) << endl;
    cout << maxLenOP(arr, n, sum) << endl;

    return 0;
}