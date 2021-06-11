#include <iostream>
using namespace std;

int binarySearchInc(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = high + (low - high) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > x)
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}

int binarySearchIDes(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = high + (low - high) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int search(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        {
            cout << arr[mid] << endl;
            int right = binarySearchIDes(arr, mid, n - 1, x);
            return (right == -1) ? binarySearchInc(arr, 0, mid - 1, x) : right;
        }
        if (mid > 0 && arr[mid - 1] >= arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {5, 30, 60, 70, 20, 10, 5};
    int n = *(&arr + 1) - arr;
    int key = 20;
    cout << search(arr, n, key) << endl;
    return 0;
}