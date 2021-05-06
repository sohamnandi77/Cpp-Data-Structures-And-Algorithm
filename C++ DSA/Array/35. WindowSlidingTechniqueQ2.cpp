//* Given a array of non-negative integers.Find if there is a subarray of given sum
// ! this approach doesn't work for negative numbers
#include <iostream>
using namespace std;

bool subArraySumNOOB(int *arr, int size, int k)
{
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[i];
            if (sum == k)
                return true;
        }
    }
    return false;
}

bool subArraySumOP(int *arr, int size, int k)
{
    int curr_sum = 0, start = 0;
    for (int end = 0; end < size; end++)
    {
        // If curr_sum exceeds the sum, then remove the starting elements
        while (curr_sum > k && start < end - 1)
        {
            curr_sum -= arr[start];
            start++;
        }
        // If curr_sum becomes equal to sum, then return true
        if (curr_sum == k)
        {
            cout << "Sum found between indexes " << start << " and " << end - 1 << endl;
            return true;
        }
        // Add this element to curr_sum
        if (end < size)
            curr_sum += arr[end];
    }
    return false;
}

int main()
{
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    cout << subArraySumNOOB(arr, n, sum) << endl;
    cout << subArraySumOP(arr, n, sum) << endl;
    return 0;
}