// ? You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

#include <iostream>
#include <time.h>
#include <iomanip>
#include <algorithm>
using namespace std;

int missingNumber2(int arr[], int n)
{

    // Your code here
    int *H = new int[1000000]{0};
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            H[arr[i]]++;
    }
    int x;
    for (int i = 1; i < 1000000; i++)
    {
        if (H[i] == 0)
        {
            x = i;
            break;
        }
    }
    delete[] H;
    return x;
}

int missingNumber(int arr[], int n)
{
    sort(arr, arr + n);
    int i = 0, k = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            break;
        }
    }
    int max1 = 1;
    for (k = i; k < n; k++)
    {
        if (arr[k] > max1)
        {
            return max1;
        }
        if (arr[k] == arr[k - 1])
            continue;
        max1++;
    }
    return max1;
}

int main()
{

    int arr[] = {0, 1, 1, 2, 2, 3, 3, 4};
    cout << missingNumber(arr, 8) << endl;
    cout << missingNumber2(arr, 8) << endl;
    return 0;
}
