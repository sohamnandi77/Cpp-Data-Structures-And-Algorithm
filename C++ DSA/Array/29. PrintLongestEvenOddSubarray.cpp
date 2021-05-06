#include <iostream>
using namespace std;

void printLongestEvenOddOP(int arr[], int n)
{
    int res = 1, curr = 1, endIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
        {
            curr++;
            if (res < curr)
            {
                res = curr;
                endIndex = i;
            }
        }
        else
            curr = 1;
    }
    int startIndex = endIndex - res + 1;

    for (int i = startIndex; i <= endIndex; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {5, 10, 20, 6, 3, 8}, n = 6;
    printLongestEvenOddOP(arr, n);
    return 0;
}