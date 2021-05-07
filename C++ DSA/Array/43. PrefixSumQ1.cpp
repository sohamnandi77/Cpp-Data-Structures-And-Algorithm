// ? Given a fixed array and multiple queries of following types on the array, how to efficiently perform these queries.

#include <iostream>
using namespace std;

int getSum(int *arr, int l, int r)
{
    if (l != 0)
        return arr[r] - arr[l - 1];
    else
        return arr[r];
}

int main()
{
    // Prefix Sum
    int arr[7] = {2, 8, 3, 9, 6, 5, 4};
    int size = 7;
    int *a = new int[size]{0};
    int sum = arr[0];
    a[0] = arr[0];

    for (int i = 1; i < size; i++)
    {
        sum += arr[i];
        a[i] = sum;
    }

    cout << getSum(a, 3, 5) << endl;

    delete[] a;
    return 0;
}