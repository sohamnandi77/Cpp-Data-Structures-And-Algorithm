#include <iostream>
using namespace std;
int LastIndex(int arr[], int n, int low, int high, int x)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] > x)
        return LastIndex(arr, n, low, mid - 1, x);
    else if (arr[mid] < x)
        return LastIndex(arr, n, mid + 1, high, x);

    else
    {
        if (arr[mid] == n - 1 || arr[mid + 1] != arr[mid])
            return mid;
        else
            return LastIndex(arr, n, mid + 1, high, x);
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 8, 9, 10};
    int size = *(&arr + 1) - arr;
    int x = 8;
    cout << LastIndex(arr, size, 0, size - 1, x) << endl;

    return 0;
}