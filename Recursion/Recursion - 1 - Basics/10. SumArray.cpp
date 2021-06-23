#include <iostream>
using namespace std;

int sum(int *arr, int i, int n)
{

    if (i == n)
        return 0;

    return arr[i] + sum(arr, i + 1, n);
}

int sum(int *arr, int n)
{

    if (n == 0)
        return 0;

    return arr[0] + sum(arr + 1, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = 4;
    cout << sum(arr, n) << endl;
    return 0;
}