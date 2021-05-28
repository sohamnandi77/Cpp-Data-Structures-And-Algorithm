#include <iostream>
using namespace std;

// Here we are Traversing the array from left to right.
int first_index(int a[], int size, int ele)
{
    // Base case
    if (size == 0)
        return INT_MIN;

    // small calculations
    if (a[0] == ele)
        return 0;

    // Recursive call
    int ans = first_index(a + 1, size - 1, ele);

    if (ans == INT_MIN)
        return -1;

    return ans + 1;
}

//* This method is for Unsorted Array
//* For a Sorted array, Look For Binary Search
int main()
{
    int arr[] = {6, 5, -1, 7, 3};
    int n = *(&arr + 1) - arr;
    cout << first_index(arr, n, -1) << endl;
    return 0;
}