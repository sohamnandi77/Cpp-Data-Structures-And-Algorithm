#include <iostream>
using namespace std;
void mergeTwoSortedArray(int a[], int b[], int n, int m, int c[])
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (a[i] <= b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < m)
        c[k++] = a[i++];

    while (j < n)
        c[k++] = b[j++];
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int n1 = *(&arr1 + 1) - arr1;

    int arr2[] = {2, 4, 6, 8};
    int n2 = *(&arr2 + 1) - arr2;

    int size = n1 + n2;
    int *arr3 = new int[size];

    mergeTwoSortedArray(arr1, arr2, n1, n2, arr3);

    cout << "Array after merging" << endl;
    for (int i = 0; i < size; i++)
        cout << arr3[i] << " ";

    delete arr3;
    return 0;
}