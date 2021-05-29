// ? You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

#include <iostream>
#include <time.h>
#include <iomanip>
#include <algorithm>
using namespace std;

int missingNumberNoob(int arr[], int n)
// # Time Complexity : O(nlogn)
// # Space Complexity: O(1)
{
    sort(arr, arr + n);
    int i = 0, k = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            break;
    }
    int max1 = 1;
    for (k = i; k < n; k++)
    {
        if (arr[k] > max1)
            return max1;
        if (arr[k] == arr[k - 1])
            continue;
        max1++;
    }
    return max1;
}

int missingNumberBetter(int arr[], int n)
// # Time Complexity: O(n)
// # Space Complexity: O(n)
// * Same approach can be done using hashset
{

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

int segregateArr(int arr[], int n)
{
    int j = 0, i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
        {
            //changing the position of negative numbers and 0.
            swap(arr[i], arr[j]);
            //incrementing count of non-positive integers.
            j++;
        }
    }
    return j;
}

//Finding the smallest positive missing number in an array that contains only positive integers.
int findMissingPositive(int arr[], int n)
{
    //marking arr[i] as visited by making arr[arr[i]-1] negative.
    //note that 1 is subtracted because indexing starts from 0 and
    //positive numbers start from 1.
    for (int i = 0; i < n; i++)
        if (abs(arr[i]) - 1 < n && arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];

    for (int i = 0; i < n; i++)
        if (arr[i] > 0)
            //returning the first index where value is positive.
            // 1 is added because indexing starts from 0.
            return i + 1;
    return n + 1;
}

int missingNumberOP(int arr[], int n)
// # Time Complexity: O(n)
// # Space Complexity: O(1)
{
    //first separating positive and negative numbers.
    int shift = segregateArr(arr, n);

    //shifting the array to access only positive part.
    //calling function to find result and returning it.
    return findMissingPositive(arr + shift, n - shift);
}

int main()
{

    int arr[] = {0, 1, 1, 3, 3, 4};
    int n = *(&arr + 1) - arr;
    cout << missingNumberNoob(arr, n) << endl;
    cout << missingNumberBetter(arr, n) << endl;
    cout << missingNumberOP(arr, n) << endl;
    return 0;
}
