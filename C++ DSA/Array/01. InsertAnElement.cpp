#include <iostream>
using namespace std;
int insert(int *arr, int n, int x, int cap, int pos)
{
    if (n == cap)
        return n;

    int idx = pos - 1;

    for (int i = n - 1; i >= idx; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[idx] = x;

    return n + 1;
}
int main()
{

    //  initialize a dynamic array using an initializer list
    int *arr{new int[10]{10, 7, 15, 3, 11}};
    int cap = 10, n = 5;

    cout << "Before Insertion" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int x = 7, pos = 2;

    n = insert(arr, n, x, cap, pos);

    cout << "After Insertion" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}