// Given n ranges, find the Maximum Occuring Element in all the ranges
// 0 <= l[i], r[i] <= 1000

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxOcc(int *start, int *end, int n)
{
    vector<int> arr(1000);
    for (int i = 0; i < n; i++)
    {
        arr[start[i]]++;
        arr[end[i] + 1]--;
    }

    int maxNum = *max_element(end, end + n);

    int maxEle = arr[0], res = 0;
    for (int i = 1; i < maxNum; i++)
    {
        arr[i] += arr[i - 1];
        if (maxEle < arr[i])
        {
            maxEle = arr[i];
            res = i;
        }
    }
    return res;
}

int main()
{
    int L[] = {1, 2, 3}, R[] = {3, 5, 7}, n = 3;

    cout << maxOcc(L, R, n);

    return 0;
}
