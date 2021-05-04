#include <iostream>
using namespace std;

// Noob Method
int searchNoob(int arr[], int x)
{
    int i = 0;
    while (true)
    {
        if (arr[i] == x)
            return i;
        if (arr[i] > x)
            return -1;
        i++;
    }
}

//* OP Method
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

int searchOP(int arr[], int x)
{
    if (arr[0] == x)
        return 0;
    int i = 0;
    while (arr[i] < x)
    {

        if (arr[i] == x)
            return i;
        i = i * 2;
    }

    return binarySearch(arr, i / 2 + 1, i - 1, x);
}

int main()
{
    int arr[] = {2, 8, 10, 12, 14, 18, 20, 22};

    int x = 20;

    cout << searchNoob(arr, x);

    return 0;
}