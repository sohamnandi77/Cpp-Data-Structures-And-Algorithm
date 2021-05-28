// * Complexity -> O(n^2) (in all cases)
// * Not Stable, In place
// # Does less memory writes compared to quick sort, merge sort ,insertion sort etc
// Memory writes are most costly in EPROM
// ? But cycle sort is most optimal for memory writes.
// Basic idea for Heap Sort

#include <iostream>
using namespace std;

//* Find the minimum element in unsorted array and swap it with element at begining

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[min_idx] > arr[j])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

int main()
{
    int arr[] = {12, 56, 71, -2, 10, 19, 54, 25};
    int size = *(&arr + 1) - arr;
    selectionSort(arr, size);
    for (int x : arr)
        cout << x << " ";

    return 0;
}