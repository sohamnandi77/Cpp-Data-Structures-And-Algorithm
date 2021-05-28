#include <iostream>
using namespace std;

int allIndices(int *arr, int size, int x, int *arr2)
{
    // Base Case
    if (size == 0)
        return 0;

    // Recursive Call
    // here it will traverse from left to right
    int OutputSize = allIndices(arr + 1, size - 1, x, arr2);

    // A small Calculation
    // indirectly it will traverse from right to left

    // update each element of output array by 1
    for (int i = OutputSize - 1; i >= 0; i--)
        arr2[i]++;

    // shift the output array by 1 and update 0th element of arr2 with 0
    if (arr[0] == x)
    {
        for (int i = OutputSize - 1; i >= 0; i--)
            arr2[i + 1] = arr2[i];
        arr2[0] = 0;
        OutputSize++;
    }
    return OutputSize;
}

void allIndices(int *arr, int size, int x)
{
    int *arr2 = new int[size];
    int n = allIndices(arr, size, x, arr2);
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";

    delete[] arr2;
}

int main()
{
    int arr[] = {5, 6, 5, 5, 6};
    int size = *(&arr + 1) - arr;
    allIndices(arr, size, 5);
    return 0;
}