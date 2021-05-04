#include <iostream>
using namespace std;

void moveZerosToEndNOOB(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] != 0)
                    swap(arr[j], arr[i]);
            }
        }
    }
}

void moveZerosToEndOP(int *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}
int main()
{
    int arr[] = {10, 8, 0, 0, 12, 0}, n = *(&arr + 1) - arr;

    cout << "Before Moving" << endl;

    for (int x : arr)
    {
        cout << x << " ";
    }

    cout << endl;

    moveZerosToEndNOOB(arr, n);
    moveZerosToEndOP(arr, n);

    cout << "After Moving" << endl;

    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}