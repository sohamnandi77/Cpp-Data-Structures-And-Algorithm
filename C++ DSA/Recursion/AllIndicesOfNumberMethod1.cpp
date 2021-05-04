#include <iostream>
using namespace std;
int allIndices(int *arr, int size, int x, int *arr2)
{
    // Base Case
    if (size == 0)
        return 0;

    // Recursive Call
    int OutputSize = allIndices(arr + 1, size - 1, x, arr2);

    // A small Calculation

    // shift the output array by 1 and add 1 to array values
    if (arr[0] == x)
    {
        for (int i = OutputSize - 1; i >= 0; i--)
        {
            arr2[i + 1] = arr2[i] + 1;
        }
        arr2[0] = 0;

        OutputSize++;
    }
    else // update each element of output array by 1
    {
        for (int i = OutputSize - 1; i >= 0; i--)
        {
            arr2[i]++;
        }
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