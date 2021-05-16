// * Time Complexity: O(nlog n)
// * Worst Case Time: O(n^2)
// ? Despite O(n^2) it's faster than Merge Sort
// # Cache Friendly
// # Tail recursive

#include <iostream>
using namespace std;

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

void QuickSort(int *arr, int l, int h)
{
    if (l < h)
    {
        int p = LomutoPartition(arr, l, h);
        QuickSort(arr, l, p - 1);
        QuickSort(arr, p + 1, h);
    }
}

int main()
{
    int arr[] = {5, 13, 6, 9, 12, 11, 8};
    int n = *(&arr + 1) - arr;
    int l = 0, h = n - 1;
    QuickSort(arr, l, h);
    for (int x : arr)
        cout << x << " ";
    return 0;
}