#include <iostream>
using namespace std;

bool compare(int a, int b)
{
    return a < b;
}

// Bubble Sort
void BubbleSort(int arr[], int n, bool (&cmp)(int a, int b))
{
    for (int i = 0; i < n - 1; i++)
    {
        bool sorted = true;
        for (int j = 0; j < (n - 1 - i); j++)
        {
            if (cmp(arr[j], arr[j + 1]))
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
    int arr[] = {12, 65, 85, 21, 36, 91, 42, 75, 2, 21};
    int n = *(&arr + 1) - arr;
    for (int x : arr)
        cout << x << " ";

    cout << endl;
    BubbleSort(arr, n, compare);

    for (int x : arr)
        cout << x << " ";
    return 0;
}