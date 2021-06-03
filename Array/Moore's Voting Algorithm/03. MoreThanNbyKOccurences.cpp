#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int countOccurenceNoob(int *arr, int n, int k)
// # Time Complexity: O(n^2)
// # Space Complexity: O(1)
{
    int count = 0, res = 0, diff = n / k;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > diff)
        {
            res++;
            count = 0;
        }
    }

    return res;
}

int countOccurenceBetter(int *arr, int n, int k)
// # Time Complexity: O(nlog(n))
// # Space Complexity: O(1)
{
    sort(arr, arr + n);
    int min_count = n / k;
    int count_ele = 0;
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == arr[i - 1])
            count++;
        if (arr[i] != arr[i - 1] || arr[i] == arr[n])
        {
            if (count > min_count)
                count_ele++;
            count = 1;
        }
    }

    return count_ele;
}

int countOccurenceSpace(int *arr, int n, int k)
// # Time Complexity: O(n)
// # Space Complexity: O(1)
{
    int *a = new int[1000000];
    int count = 0, diff = n / k;
    for (int i = 0; i < n; i++)
        a[arr[i]]++;
    for (int i = 1; i < 100000; i++)
        if (a[i] > diff)
            count++;
    delete[] a;
    return count;
}

// # Better Solutions are discussed in Hashing Track

// * For more Refer: https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/

int main()
{
    int arr[] = {7, 8, 9, 7, 6, 8, 6, 6};
    int size = *(&arr + 1) - arr;
    int k = 3;
    cout << countOccurenceNoob(arr, size, k) << endl;
    cout << countOccurenceBetter(arr, size, k) << endl;
    cout << countOccurenceSpace(arr, size, k) << endl;
    return 0;
}