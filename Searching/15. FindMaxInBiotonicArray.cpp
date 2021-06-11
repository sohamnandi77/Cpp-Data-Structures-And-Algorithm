#include <iostream>
using namespace std;

int getPeak(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
            return arr[mid];
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
    cout << getPeak(arr, n) << endl;
    return 0;
}