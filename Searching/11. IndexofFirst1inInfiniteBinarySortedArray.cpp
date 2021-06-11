#include <iostream>
using namespace std;

int FirstIndex(int arr[], int low, int high, int x)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x)
            high = mid - 1;

        else if (arr[mid] < x)
            low = mid + 1;

        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid;

            else
                high = mid - 1;
        }
    }

    return -1;
}

int search(int arr[], int x)
{
    if (arr[0] == x)
        return 0;
    int i = 1;
    while (arr[i] < x)
        i *= 2;

    return FirstIndex(arr, i / 2 + 1, i - 1, x);
}

int main()
{
    int arr[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    int x = 1;
    cout << search(arr, x);

    return 0;
}