// * Complexity -> O(n^2)
// # O(n) best case
// * Stable , Inplace

#include <iostream>
using namespace std;
//* Reapetedly swap two adjacent elements if they are in wrong order
void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool sorted = true;
        for (int j = 0; j < (n - 1 - i); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                sorted = false;
            }
        }
        if (sorted)
            break;
    }
}

int main()
{
    int arr[] = {12, 56, 71, 31, 10, 19, 54, 25};
    int size = *(&arr + 1) - arr;
    BubbleSort(arr, size);
    for (int x : arr)
        cout << x << " ";
    return 0;
}