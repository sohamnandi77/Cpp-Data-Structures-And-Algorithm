#include <iostream>
using namespace std;

void printSubarrays(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            // Elements of Subarrays
            for (int k = i; k <= j; k++)
                cout << arr[k] << ",";
            cout << endl;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = *(&arr + 1) - arr;
    printSubarrays(arr, n);
    return 0;
}