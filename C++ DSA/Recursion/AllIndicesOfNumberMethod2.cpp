#include <iostream>
using namespace std;
int allIndices(int *arr, int size, int x, int *arr2)
{
    // Base Case
    if (size == 0)
        return 0;

    // Recursive Call
    int OutputSize = allIndices(arr, size - 1, x, arr2);

    // A small Calculation

    // shift the output array by 1 and add 1 to array values
    if (arr[size - 1] == x)
    {
        arr2[OutputSize] = size - 1;

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