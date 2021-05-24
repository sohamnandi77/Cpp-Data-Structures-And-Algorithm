// ? Problem : https://www.interviewbit.com/problems/repeat-and-missing-number-array/

#include <iostream>
using namespace std;

void swapSort(int *arr, int n)
{
    // Preprocessing
    int i = 0;
    while (i < n)
    {
        if (arr[i] != arr[arr[i] - 1])
            swap(arr[i], arr[arr[i] - 1]);
        else
            i++;
    }

    // Observation
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
            cout << "Missing Number: " << i + 1 << " Duplicate Number: " << arr[i] << endl;
    }
}

int main()
{
    int arr[] = {3, 1, 1, 5, 3};
    int n = *(&arr + 1) - arr;
    swapSort(arr, n);
    return 0;
}