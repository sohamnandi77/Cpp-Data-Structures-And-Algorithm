// * Complexity -> O(n^2)
// # O(n) best case
// * Stable, In place
// ? Used in practice for small arrays (Tim sort and Intro Sort)

#include <iostream>
using namespace std;
//* Insert an element from unsorted array to its correct position in sorted array
void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n - 1; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) // ! arr[j] >= key will make it unstable
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {12, 56, 71, -2, 10, 19, 54, 25};
    int size = *(&arr + 1) - arr;
    InsertionSort(arr, size);
    for (int x : arr)
        cout << x << " ";
    return 0;
}