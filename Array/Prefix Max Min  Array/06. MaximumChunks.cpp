#include <iostream>
using namespace std;

int maxChunk(int *arr, int n)
{
    int pmax = INT_MIN;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        pmax = max(pmax, arr[i]);
        if (pmax == i)
            count++;
    }
    return count;
}

int main()
{
    int arr[] = {1, 2, 0, 4, 3, 5};
    int n = *(&arr + 1) - arr;
    cout << maxChunk(arr, n) << endl;
    return 0;
}