// ? finding the Kth smallest element from a given array.
// # For O(nlogk) Solution , Use Heap method

#include <iostream>
#include <algorithm>
using namespace std;

int KthSmallestElementNoob(int *arr, int n, int k)
// * Average Case: O(nlogn)
{
    sort(arr, arr + n);
    return arr[k - 1];
}

int LomutoPartition(int *arr, int l, int h)
// * Not Stable, In Place
{
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

// Quick Select
int KthSmallestElementOP(int *arr, int n, int k)
// * Average Case: O(n)
// ! Worst Case: O(n^2)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int p = LomutoPartition(arr, l, r);
        if (p = k - 1)
            return arr[p];
        else if (p > k - 1)
            r = p - 1;
        else
            r = p + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {5, 13, 6, 9, 12, 11, 8};
    int n = *(&arr + 1) - arr;
    int k = 5;
    cout << "Noob Method" << endl;
    cout << KthSmallestElementNoob(arr, n, k) << endl;
    cout << "OP Method" << endl;
    cout << KthSmallestElementOP(arr, n, k) << endl;
    for (int x : arr)
        cout << x << " ";
    return 0;
}