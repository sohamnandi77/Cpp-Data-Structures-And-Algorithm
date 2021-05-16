// * Complexity -> O(N*logN) and Space Complexity -> O(N)
// * Stable, not in place (but Block Merge Sort is in place)
// # Well Suited for Linked List
// ? Quick Sort performs better in case of Arrays than Merge Sort

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int h)
{

    // * Setting Up auxiliary arrays
    int n1 = m - l + 1, n2 = h - m;

    int *left = new int[n1];
    int *right = new int[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // * standard merge Logic
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    delete[] left, right;
}

void MergeSort(int arr[], int l, int r)
{

    if (r > l)
    {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {10, 15, 20, 40, 8, 11, 15, 22, 25};
    int size = *(&arr + 1) - arr;
    MergeSort(arr, 0, size - 1);
    for (int x : arr)
        cout << x << " ";
    return 0;
}