#include <iostream>
using namespace std;

int first_index(int a[], int size, int ele)
{
    // Base case
    if (size == 0)
    {
        return -1;
    }
    // small calculations
    if (a[0] == ele)
    {
        return 0;
    }
    // Recursive call
    else
    {
        return first_index(a + 1, size - 1, ele) + 1;
    }
}

//* This method is for Unsorted Array
//* For a Sorted array, Look For Binary Search
int main()
{
    int arr[5] = {6, 5, 7, 7, 3};
    cout << first_index(arr, 5, 7) << endl;
    return 0;
}