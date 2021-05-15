#include <iostream>
using namespace std;

int HoarePartition(int *arr, int l, int h)
// * Not Stable, In Place
// ? Works better than Lomuto Partition
{
    int pivot = arr[l];
    int i = l - 1, j = h + 1;
    while (true)
    {
        do
            i++;
        while (arr[i] < pivot);
        do
            j--;
        while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j]);
    }
}

void QuickSort(int *arr, int l, int h)
{
    // Create an auxiliary stack
    int *stack = new int[h - l + 1];

    // initialize top of stack
    int top = -1;

    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;

    // Keep popping from stack while is not empty
    while (top >= 0)
    {
        // Pop h and l
        h = stack[top--];
        l = stack[top--];

        // Set pivot element at its correct position
        // in sorted array
        int p = HoarePartition(arr, l, h);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > l)
        {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < h)
        {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
    delete[] stack;
}

int main()
{
    int arr[] = {5, 13, 6, 9, 12, 11, 8};
    int n = *(&arr + 1) - arr;
    int l = 0, h = n - 1;
    QuickSort(arr, l, h);
    for (int x : arr)
        cout << x << " ";
    return 0;
}