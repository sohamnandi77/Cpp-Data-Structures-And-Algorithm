#include <iostream>
using namespace std;

void naivePartition(int *arr, int l, int h, int p)
// * Stable, Not In Place
{
    int *temp = new int[h - l + 1];
    int index = 0;
    for (int i = l; i <= h; i++)
        if (arr[i] <= arr[p])
        {
            temp[index] = arr[i];
            index++;
        }
    for (int i = l; i <= h; i++)
        if (arr[i] > arr[p])
        {
            temp[index] = arr[i];
            index++;
        }
    for (int i = l; i <= h; i++)
        arr[i] = temp[i - l];
    delete[] temp;
}

void LomutoPartition(int *arr, int l, int h, int p)
// * Not Stable, In Place
{
    swap(arr[p], arr[h]);
    int pivot = arr[h];
    int i = l - 1;
    for (int j = 0; j <= h - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
}

void HoarePartition(int *arr, int l, int h, int p)
// * Not Stable, In Place
// ? Works better than Lomuto Partition
{
    swap(arr[p], arr[l]);
    int pivot = arr[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j++;
        } while (arr[j] > pivot);
        if (i >= j)
            return;
        swap(arr[i], arr[j]);
    }
}

int main()
{
    int arr[] = {5, 13, 6, 9, 12, 11, 8};
    int n = *(&arr + 1) - arr;
    int l = 0, h = n - 1, p = n - 1;
    naivePartition(arr, l, h, p);
    for (int x : arr)
        cout << x << " ";
    return 0;
}