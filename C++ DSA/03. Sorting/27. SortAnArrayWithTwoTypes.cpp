// ? segregate an array of elements containing two types of elements. The types are:
/* 
* Segregate negative and positive elements.
* Segregate even and odd elements.
* Sort a binary array.
*/

#include <iostream>
#include <algorithm>
using namespace std;

void SegregateNoob(int *arr, int n)
{
    int *temp = new int[n];
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] < 0)
            temp[i++] = arr[j];
    }
    for (int j = 0; j < n; j++)
    {
        if (arr[j] > 0)
            temp[i++] = arr[j];
    }
    for (int j = 0; j < n; j++)
    {
        arr[j] = temp[j];
    }
    delete[] temp;
}

void SegregateOP(int *arr, int n)
// * Based on Hoare's Partition
{
    int i = -1, j = n;
    while (true)
    {
        do
            i++;
        while (arr[i] < 0);
        do
            j--;
        while (arr[j] >= 0);
        if (i >= j)
            return;
        swap(arr[i], arr[j]);
    }
}

int main()
{
    int arr[] = {13, -12, 18, -10};
    int n = *(&arr + 1) - arr;
    cout << "Before Segregating" << endl;
    for (int x : arr)
        cout << x << " ";

    cout << endl;
    // SegregateNoob(arr, n);
    SegregateOP(arr, n);

    cout << "After Segregating" << endl;
    for (int x : arr)
        cout << x << " ";
    return 0;
}