#include <iostream>
using namespace std;

// Here we are Traversing the array from right to left.
int last_index(int a[], int size, int ele)
{
    // Base case
    if (size <= 0)
        return -1;

    // small calculations
    if (a[size] == ele)
        return size;

    // Recursive call
    return last_index(a, size - 1, ele);
}
int main()
{
    int arr[5] = {3, 3, 4, 2, 2};
    cout << last_index(arr, 5, 2) << endl;
    return 0;
}