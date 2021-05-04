#include <iostream>
using namespace std;
int main()
{
    int *p = new int;
    *p = 10;
    cout << *p << endl;

    //* int *p = new int(10); can also be written this way

    int *a = new int[50];

    //! Bad Practice
    //? as here the memory will be stored in stack memory which is small
    // int n;
    // cin >> n;
    // int a[n];

    //* DMA in arrays
    //? here the memory will be stored in Heap memory which is large
    int n;
    cin >> n;
    int *pa = new int[n];
    delete[] pa; //* here pa is not deleted; the memory address pa was pointing that is deleted

    //! it will keep increasing the memory usage as heap memory is not deleted automatically
    // while (true)
    // {
    //     int *i = new int;
    // }

    int *ptr = new int;
    delete ptr;

    ptr = new int;
    delete ptr;

    ptr = new int[100];
    delete[] ptr;

    //* Allocation and initialization of dynamic arrays

    int *arr = new int[5]{1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}