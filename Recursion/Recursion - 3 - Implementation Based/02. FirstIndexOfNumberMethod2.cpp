#include <iostream>
using namespace std;

// Here we are Traversing the array from right to left.
int first_index(int a[], int size, int ele)
{
    int ans;

    // Base case
    if (size == 0)
        return INT_MIN;

    // Recursive call
    ans = first_index(a, size - 1, ele);

    // small calculations
    if (ans != INT_MIN)
        return ans;

    if (a[size - 1] == ele) // indirectly it's checking from left to right
        ans = size - 1;

    return ans;
}

//* This method is for Unsorted Array
//* For a Sorted array, Look For Binary Search
int main()
{
    int arr[] = {6, -1, -1, 7, 7, 3};
    int n = *(&arr + 1) - arr;
    cout << first_index(arr, n, -1) << endl;
    return 0;
}