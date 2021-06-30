// ? Problem: https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

#include <iostream>
using namespace std;

int minSwap(int *arr, int n, int k)
{
    int nums = 0; //window size
    for (int i = 0; i < n; i++)
        if (arr[i] <= k)
            nums++; //counts <=k

    if (nums == 0 || nums == n) //if all are <=k || all are >k then return zero
        return 0;

    int ans = n;
    int nums2 = 0;

    //creating 1st window
    for (int j = 0; j < nums; j++)
        if (arr[j] > k)
            nums2++; //count numbers greater than k in 1st window

    ans = min(ans, nums2);

    int l = 0, r = nums - 1; //initial window size
    while (r < n - 1)
    {
        if (arr[l] > k) //excluding left most
            nums2--;
        l++;
        r++;
        if (arr[r] > k) //including right most
            nums2++;

        ans = min(ans, nums2);
    }
    return ans;
}

int main()
{
    int arr[] = {2, 7, 9, 5, 8, 7, 4};
    int n = *(&arr + 1) - arr;
    int k = 6;
    cout << minSwap(arr, n, k) << endl;
    return 0;
}