#include <iostream>
using namespace std;
int LastIndex(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            if (arr[mid] == n - 1 || arr[mid + 1] != arr[mid])
                return mid;
            else
                low = mid + 1;
        }
    }

    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 8, 9, 10};
    int size = *(&arr + 1) - arr;
    int x = 8;
    cout << LastIndex(arr, size, x) << endl;
    return 0;
}