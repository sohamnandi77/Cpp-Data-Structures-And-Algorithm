// ? Split array in three equal sum subarrays

#include <iostream>
using namespace std;

bool checkSubarr(int *arr, int size)
{
    int totalSum = 0;
    for (int i = 0; i < size; i++)
        totalSum += arr[i];

    if ((3 + (totalSum % 3)) % 3 != 0)
        return false;

    int prefixSum = 0;
    for (int i = 0; i < size; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == totalSum / 3)
            return true;
    }
    return false;
}

int main()
{
    int arr[] = {1, 3, 4, 5, -1}, n = 5;
    cout << checkSubarr(arr, n) << endl;
    return 0;
}