// ? segregate an array of elements containing three types of elements. The types are:
/* 
* Sort an array of 0s, 1s, 2s.
* Three-way partitioning when multiple occurrences of a pivot may exist.
* Partitioning around a range.
*/

// # Also Know as DNF sort (Dutch National Flag)

#include <iostream>
#include <algorithm>
using namespace std;

void SortNoob(int *arr, int n)
{
    int *temp = new int[n];
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] == 0)
            temp[i++] = arr[j];
    }
    for (int j = 0; j < n; j++)
    {
        if (arr[j] == 1)
            temp[i++] = arr[j];
    }
    for (int j = 0; j < n; j++)
    {
        if (arr[j] == 2)
            temp[i++] = arr[j];
    }
    for (int j = 0; j < n; j++)
        arr[j] = temp[j];
    delete[] temp;
}

void DNFsort(int *arr, int n)
// * Based on Hoare's Partition
// * Time Complexity: O(n) (one Traversal)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
            swap(arr[mid++], arr[low++]);
        else if (arr[mid] == 1)
            mid++;
        else
            swap(arr[mid], arr[high--]);
    }
}

// * Another implementation of DNF sort using switch case
void sort012(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        switch (arr[mid])
        {
        case 0:
            swap(arr[low++], arr[mid++]);
            break;

        case 1:
            mid++;
            break;

        default:
            swap(arr[mid], arr[high--]);
            break;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 1, 2, 0, 1};
    int n = *(&arr + 1) - arr;
    cout << "Before Segregating" << endl;
    for (int x : arr)
        cout << x << " ";

    cout << endl;
    SortNoob(arr, n);
    DNFsort(arr, n);
    sort012(arr, n);

    cout << "After Segregating" << endl;
    for (int x : arr)
        cout << x << " ";
    return 0;
}
