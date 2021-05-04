#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > x)
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x = 4;
    int size = *(&arr + 1) - arr;

    cout << binarySearch(arr, size, x) << endl;

    return 0;
}