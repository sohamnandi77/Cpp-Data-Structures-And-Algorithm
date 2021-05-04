#include <iostream>
using namespace std;

//* Find the minimum element in unsorted array and swap it with element at begining

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
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