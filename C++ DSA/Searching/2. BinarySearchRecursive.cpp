#include <iostream>
using namespace std;
int binarySearch(int arr[], int low, int high, int x)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == x)
        return mid;

    else if (arr[mid] > x)
        return binarySearch(arr, low, mid - 1, x);

    else
        return binarySearch(arr, mid + 1, high, x);
}
int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 4;
    int size = *(&arr + 1) - arr;
    cout << binarySearch(arr, 0, size - 1, x) << endl;

    return 0;
}