// ? Pivot element in sorted and rotated Array

#include <iostream>
using namespace std;

int pivot(int *arr, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] < arr[mid - 1])
            return mid - 1;
        else if (arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid] >= arr[low])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 40, 60, 5, 8};
    int n = *(&arr + 1) - arr;
    cout << pivot(arr, 0, n - 1) << endl;
    return 0;
}
