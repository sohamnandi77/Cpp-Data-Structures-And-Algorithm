#include <iostream>
using namespace std;
int countAndMerge(int arr[], int l, int m, int r)
{

    int n1 = m - l + 1, n2 = r - m;

    int *left = new int[n1];
    int *right = new int[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l, res = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
        {
            arr[k++] = right[j++];
            res += n1 - i;
        }
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    delete[] left, right;

    return res;
}

int countInv(int arr[], int l, int r)
{
    int res = 0;
    if (r > l)
    {
        int m = l + (r - l) / 2;
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};

    int n = *(&arr + 1) - arr;

    cout << countInv(arr, 0, n - 1);

    return 0;
}