#include <iostream>
using namespace std;

void FirstNegativeNumberNoob(int *arr, int n, int k)
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
}

void FirstNegativeNumberOP(int *arr, int n)
{
}

int main()
{
    int arr[] = {12, -1, -7, 8, -18, 30, 13, 28};
    int n = *(&arr + 1) - arr;
    int k = 3;
    FirstNegativeNumberNoob(arr, n, k);
    return 0;
}