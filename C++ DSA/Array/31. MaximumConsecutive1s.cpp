// ? Maximum Consecutive 1s in the array

#include <iostream>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }

int maxConsecutive1s(int arr[], int n)
{
    int curr = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            curr = 0;
        else
        {
            curr++;
            res = max(res, curr);
        }
    }
    return res;
}

int main()
{

    int arr[] = {0, 1, 0, 1, 1, 0, 1}, n = 7;
    cout << maxConsecutive1s(arr, n);
    return 0;
}