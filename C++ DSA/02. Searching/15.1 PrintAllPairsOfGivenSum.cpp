#include <iostream>
#include <algorithm>
using namespace std;

void printAllPairs(int *arr, int n, int x)
{
    sort(arr, arr + n);
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (arr[l] + arr[r] == x)
        {
            cout << arr[l] << "," << arr[r] << endl;
            l++;
            r--;
        }
        else if (arr[l] + arr[r] > x)
            r--;
        else
            l++;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = *(&arr + 1) - arr;
    int target = 5;
    printAllPairs(arr, n, target);
    return 0;
}