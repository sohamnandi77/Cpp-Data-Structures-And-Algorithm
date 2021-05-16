// * Time Complexity: O(nlog n)
// * Worst Case Time: O(n^2)
// ? Despite O(n^2) it's faster than Merge Sort
// # Cache Friendly
// # Tail recursive

#include <iostream>
using namespace std;

int HoarePartition(int *arr, int l, int h)
// * Not Stable, In Place
// ? Works better than Lomuto Partition
{
    int pivot = arr[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

void QuickSort(int *arr, int l, int h)
{
    if (l < h)
    {
        int p = HoarePartition(arr, l, h);
        QuickSort(arr, l, p);
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