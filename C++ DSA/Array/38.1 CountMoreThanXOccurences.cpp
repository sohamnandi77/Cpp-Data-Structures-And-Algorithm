#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int countOccurenceSpace(int *arr, int n, int k)
{
    int *a = new int[1000000];
    int count = 0, diff = n / k;
    for (int i = 0; i < n; i++)
        a[i]++;
    for (int i = 1; i < 100000; i++)
    {
        if (a[i] > diff)
            count++;
    }
    delete[] a;
    return count;
}
int countOccurence(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int min_count = n / k;
    int count_ele = 0;
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == arr[i - 1])
            count++;
        if (arr[i] != arr[i - 1] || arr[i] == arr[n])
        {
            if (count > min_count)
                count_ele++;
            count = 1;
        }
    }

    return count_ele;
}

// * For more Refer: https://www.geeksforgeeks.org/print-all-array-elements-appearing-more-than-n-k-times/

int main()
{
    int arr[] = {7, 8, 9, 7, 6, 8, 6, 6};
    int size = *(&arr + 1) - arr;
    int k = 3;
    cout << countOccurenceSpace(arr, size, k) << endl;
    cout << countOccurence(arr, size, k) << endl;
    return 0;
}