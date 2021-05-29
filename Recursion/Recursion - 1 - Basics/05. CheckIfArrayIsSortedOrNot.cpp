#include <iostream>
using namespace std;
bool is_sorted(int a[], int n)
{
    if (n == 1 || n == 0)
        return true;

    // if (a[0] > a[1])
    //     return false;

    if (a[n - 1] < a[n - 2])
        return false;
    return is_sorted(a, n - 1);
}

int main()
{
    int arr[] = {0, 1, 2, 2, 3, 4, 5, 6};
    int n = *(&arr + 1) - arr;
    cout << is_sorted(arr, n) << endl;
    return 0;
}