// ? Given an integer array representing the heights of N buildings, the task is to delete N - 2 buildings such that the water that can be trapped between the remaining two building is maximum.
// * Note : The total water trapped between two buildings is gap between them(number of buildings removed) multiplied by height of the smaller building.

#include <iostream>
using namespace std;

int maxWater(int height[], int n)
{
    int l = 0, r = n - 1, res = 0;
    while (l < r)
    {
        int total = min(height[l], height[r]) * (r - l - 1);
        res = max(res, total);
        if (height[l] <= height[r])
            l++;
        else
            r--;
    }
    return res;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};
    int size = *(&arr + 1) - arr;
    cout << maxWater(arr, size) << endl;
    return 0;
}