// ? Count 1s in the sorted array

#include <iostream>
using namespace std;
int Count1s(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            return n - i;
    }
    return 0;
}

int main()
{
    int arr[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    int size = *(&arr + 1) - arr;
    cout << Count1s(arr, size) << endl;
    return 0;
}