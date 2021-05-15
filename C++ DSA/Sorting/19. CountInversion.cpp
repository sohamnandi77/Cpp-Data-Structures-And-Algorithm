#include <iostream>
using namespace std;

int countInvNoob(int *arr, int n)
{
    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                res++;
        }
    }
    return res;
}

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

int countInvOP(int arr[], int l, int r)
{
    int res = 0;
    if (r > l)
    {
        int m = l + (r - l) / 2;
        res += countInvOP(arr, l, m);
        res += countInvOP(arr, m + 1, r);
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    int n = *(&arr + 1) - arr;
    cout << "Noob Method" << endl;
    cout << countInvNoob(arr, n) << endl;
    cout << "OP Method" << endl;
    cout << countInvOP(arr, 0, n - 1) << endl;

    return 0;
}