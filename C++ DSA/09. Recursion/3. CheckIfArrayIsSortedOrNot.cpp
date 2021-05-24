#include <iostream>
using namespace std;
bool is_sorted(int a[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (a[0] > a[1])
    {
        return false;
    }

    return is_sorted(a + 1, size - 1);
    // if is_sorted (a + 1, size - 1)
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    cout << is_sorted(arr, 6) << endl;
    return 0;
}