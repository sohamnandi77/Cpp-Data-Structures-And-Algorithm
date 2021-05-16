#include <iostream>
#include <unordered_set>
using namespace std;

bool isSumZeroNoob(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];
            if (curr_sum == 0)
                return true;
        }
    }
    return false;
}

bool isSumZeroOP(int *arr, int n)
{
    unordered_set<int> s;
    int pre_sum = 0;
    for (int i = 0; i < n; i++)
    {
        pre_sum += arr[i];
        if (pre_sum == 0)
            return true;
        else if (s.find(pre_sum) != s.end())
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

    cout << isSumZeroNoob(arr, n) << endl;
    cout << isSumZeroOP(arr, n) << endl;
    return 0;
}