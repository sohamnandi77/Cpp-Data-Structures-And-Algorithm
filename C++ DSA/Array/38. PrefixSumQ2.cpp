// Find if an array has a Equilibrium Point or not

#include <iostream>
using namespace std;

bool checkEquilibrium(int *arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    int leftSum = 0;
    for (int i = 0; i < size; i++)
    {
        if (leftSum == sum - arr[i])
            return true;
        leftSum += arr[i];
        sum -= arr[i];
    }
    return false;
}
int main()
{
    int arr[] = {3, 4, 8, -9, 20, 6}, n = 6;
    printf("%s", checkEquilibrium(arr, n) ? "true" : "false");

    return 0;
}