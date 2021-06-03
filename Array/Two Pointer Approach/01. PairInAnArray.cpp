#include <iostream>
#include <algorithm>
using namespace std;

//* if asked to find a Pair
//? for sorted - Two Pointer Approach
//? for unsorted - Hashing

//* if asked to find a Triplet
//? for sorted - Two Pointer Approach
//? for unsorted - sorting + Two Pointer Approach

bool isPair(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        if ((arr[left] + arr[right]) == x)
            return true;
        else if ((arr[left] + arr[right]) > x)
            right--;
        else
            left++;
    }
    return false;
}

int main()
{
    int arr[] = {2, 3, 7, 8, 11};
    int sum = 14;
    int size = *(&arr + 1) - arr;
    cout << isPair(arr, size, sum) << endl;
    return 0;
}