#include <iostream>
using namespace std;

// Method 1 was better in terms of complexity
// but this methods solves the problem by going left to right
int LastIndex(int *arr, int size, int x)
{
    // Base Case
    if (size == 0)
    {
        return -1;
    }

    // Recursion
    int ans = LastIndex(arr + 1, size - 1, x);

    // A bit calculation part
    if (ans != -1)
        return ans + 1;
    if (arr[0] == x)
        return 0;

    return ans;
}

int main()
{
    int arr[5] = {3, 3, 4, 2, 2};
    cout << LastIndex(arr, 5, 2) << endl;

    return 0;
}