#include <iostream>
#include <cmath>
using namespace std;
int max(int a, int b)
{
    return a > b ? a : b;
}

// Noob Solution
int getWaterNoob(int arr[], int n)
{
    int res = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int lMax = arr[i];

        for (int j = 0; j < i; j++)
            lMax = max(lMax, arr[j]);

        int rMax = arr[i];

        for (int j = i + 1; j < n; j++)
            rMax = max(rMax, arr[j]);

        res += (min(lMax, rMax) - arr[i]);
    }

    return res;
}

// Space Solution

int getWaterSpace(int arr[], int n)
{
    int res = 0;
    int *lMax = new int[n];
    int *rMax = new int[n];

    // left array
    lMax[0] = arr[0];
    for (int i = 1; i < n; i++)
        lMax[i] = max(arr[i], lMax[i - 1]);

    // right array
    rMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rMax[i] = max(arr[i], rMax[i + 1]);

    // Water stored
    for (int i = 1; i < n - 1; i++)
        res = res + (min(lMax[i], rMax[i]) - arr[i]);

    delete[] lMax, rMax;
    return res;
}

// OP Solution -  Two Pointer Approach

int getWaterOP(int arr[], int n)
{
    int res = 0, l = 0, r = n - 1, lMax = 0, rMax = 0;

    while (l <= r)
    {
        if (arr[l] <= arr[r])
        {
            if (arr[l] > lMax)
                lMax = arr[l];
            else
                res += lMax - arr[l];
            l++;
        }
        else
        {
            if (arr[r] > rMax)
                rMax = arr[r];
            else
                res += rMax - arr[r];
            r--;
        }
    }
    return res;
}

int main()
{

    int arr[] = {3, 0, 1, 2, 5}, n = 5;

    cout << "Noob Solution" << endl;
    cout << getWaterNoob(arr, n) << endl;
    cout << "Space Solution" << endl;
    cout << getWaterSpace(arr, n) << endl;
    cout << "OP Solution" << endl;
    cout << getWaterOP(arr, n) << endl;
}