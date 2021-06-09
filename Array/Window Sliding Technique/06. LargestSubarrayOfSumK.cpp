// ! This approach doesn't work for negative numbers

#include <iostream>
using namespace std;

int LargestSubOfSumK(int *arr, int n, int k)
{

    int i = 0, j = 0, sum = 0, mx = -1;
    while (j < n)
    {
        sum += arr[j];
        if (sum < k)
            j++;

        else if (sum == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }

        else if (sum > k)
        {
            while (sum > k)
            {
                sum -= arr[i];
                i++;
            }
            j++;
        }
    }

    return mx;
}

int main()
{
    int arr[] = {4, 1, 1, 1, 2, 3, 5};
    int n = *(&arr + 1) - arr;
    int k = 5;

    cout << LargestSubOfSumK(arr, n, k) << endl;
    return 0;
}