#include <iostream>
#include <unordered_map>
using namespace std;

int LongestCommonSpan(bool *a, bool *b, int n)
{
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
        temp[i] = a[i] - b[i];

    unordered_map<int, int> m;
    int pre_sum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += temp[i];
        if (pre_sum == 0)
            res = i + 1;
        if (m.find(pre_sum) == m.end())
            m.insert({pre_sum, i});
        if (m.find(pre_sum) != m.end())
            res = max(res, i - m[pre_sum]);
    }
    delete[] temp;
    return res;
}

int main()
{
    bool arr1[] = {0, 1, 0, 1, 1, 1, 1};
    bool arr2[] = {1, 1, 1, 1, 1, 0, 1};
    int n = *(&arr1 + 1) - arr1;
    cout << LongestCommonSpan(arr1, arr2, n) << endl;
    return 0;
}