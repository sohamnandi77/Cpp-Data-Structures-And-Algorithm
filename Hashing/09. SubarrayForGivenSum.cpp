#include <iostream>
#include <unordered_set>
using namespace std;

bool isGivenSumNoob(int *arr, int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];
            if (curr_sum == sum)
                return true;
        }
    }
    return false;
}

bool isGivenSumOP(int *arr, int n, int sum)
{
    unordered_set<int> s;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == sum)
            return true;
        else if (s.find(pre_sum - sum) != s.end())
            return true;
        else
            s.insert(pre_sum);
    }
    return false;
}

int main()
{
    int arr[] = {5, 3, 9, -4, -6, 7, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 6;

    cout << isGivenSumNoob(arr, n, k) << endl;
    cout << isGivenSumOP(arr, n, k) << endl;
    return 0;
}