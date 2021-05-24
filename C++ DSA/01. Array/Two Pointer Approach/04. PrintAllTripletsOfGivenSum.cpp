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
void printAllTriplets(int *arr, int n, int x)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            if ((arr[l] + arr[r]) == (x - arr[i]))
            {
                cout << arr[i] << "," << arr[l] << "," << arr[r] << endl;
                l++;
                r--;
            }
            else if ((arr[l] + arr[r]) > (x - arr[i]))
                r--;
            else
                l++;
        }
    }
}

int main()
{
    int arr[] = {5, 7, 9, 1, 2, 4, 6, 8, 3};
    int n = *(&arr + 1) - arr;
    int target = 10;
    printAllTriplets(arr, n, target);
    return 0;
}