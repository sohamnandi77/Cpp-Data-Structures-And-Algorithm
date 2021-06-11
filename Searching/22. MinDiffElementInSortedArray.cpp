#include <iostream>
using namespace std;

int minDiff(int *arr, int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = high + (low - high) / 2;

        if (arr[mid] == x)
            return arr[mid];
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (abs(x - arr[low]) < abs(x - arr[high]))
        return arr[low];
    return arr[high];
}

int main()
{
    int arr[] = {1, 3, 8, 10, 15};
    int n = *(&arr + 1) - arr;
    int key = 12;
    cout << minDiff(arr, n, key) << endl;
    return 0;
}