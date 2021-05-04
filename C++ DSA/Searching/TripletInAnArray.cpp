#include <iostream>
using namespace std;

bool isPair(int arr[], int left, int right, int x)
{
    // int left = 0, right = n - 1;
    while (left <= right)
    {
        if ((arr[left] + arr[right]) == x)
            return true;
        else if ((arr[left] + arr[right]) > x)
            right--;
        else
            left++;
    }
    return false;
}

bool isTriplet(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (isPair(arr, i + 1, n - 1, x - arr[i]))
            return true;
    }
    return false;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int sum = 11;
    int size = *(&arr + 1) - arr;
    cout << isTriplet(arr, size, sum) << endl;
    return 0;
}