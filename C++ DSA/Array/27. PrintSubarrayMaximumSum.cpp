#include <iostream>
using namespace std;

//* OP Method - Kadane's Algorithm

void printSubarrayMaxSum(int arr[], int n)
{
    int endIndex = 0, currMax = arr[0], globalMax = arr[0];
    for (int i = 1; i < n; i++)
    {
        currMax = max((currMax + arr[i]), arr[i]);
        if (currMax > globalMax)
        {
            globalMax = currMax;
            endIndex = i;
        }
    }

    int startIndex = endIndex;

    while (startIndex >= 0)
    {
        globalMax -= arr[startIndex];
        if (globalMax == 0)
            break;
        startIndex--;
    }

    for (int i = startIndex; i <= endIndex; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, -2, 3, -1, 2}, n = 5;
    printSubarrayMaxSum(arr, n);
    return 0;
}