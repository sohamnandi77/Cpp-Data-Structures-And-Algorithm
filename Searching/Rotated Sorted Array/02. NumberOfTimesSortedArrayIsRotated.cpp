// ? No of Rotations in clockwise = n - First Index of Minimum Element

#include <iostream>
#include <vector>
using namespace std;

int noOfRotations(int *arr, int n)
{
    // # If the array is already sorted or Zero rotations
    if (arr[0] < arr[n - 1])
        return 0;

    int pivot = -1;
    int s = 0, e = n - 1;
    while (s <= e)
    {
        // ? If End Becomes greater than start , it means Start is the minimum index
        if (arr[s] <= arr[e])
            return s;

        int mid = s + (e - s) / 2;
        int next = (mid + 1) % n;
        int prev = (mid - 1 + n) % n;

        if (arr[mid] <= arr[next] && arr[mid] < arr[prev])
        {
            pivot = mid;
            break;
        }
        if (arr[s] <= arr[mid])
            s = mid + 1;
        else if (arr[mid] <= arr[e])
            e = mid - 1;
    }

    return n - pivot; // # no of rotations in clockwise direction is (n - pivot)
}

int main()
{
    int arr[] = {11, 12, 15, 2, 2, 5, 6, 8};
    int n = *(&arr + 1) - arr;
    cout << noOfRotations(arr, n) << endl;
    return 0;
}