// ? Problem : https://www.interviewbit.com/problems/painters-partition-problem/

#include <iostream>
using namespace std;
bool isFeasible(int *arr, int n, int k, int t, int mid)
{
    int painters = 1;
    int timeTaken = 0;
    for (int i = 0; i < n; i++)
    {
        if (timeTaken + (arr[i] * t) > mid)
        {
            timeTaken = arr[i] * t;
            painters++;
            if (painters > k)
                return false;
        }
        else
            timeTaken += (arr[i] * t);
    }
    return true;
}

int minTime(int *arr, int n, int k, int t)
{
    int s = arr[0], e;
    for (int i = 1; i < n; i++)
    {
        e += arr[i];
        s = max(s, arr[i]);
    }
    s *= t;
    e *= t;
    int ans = 0;
    while (s <= e)
    {
        int mid = e + (s - e) / 2;
        if (isFeasible(arr, n, k, t, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}

int main()
{
    int painters = 2, boards = 2, timeTaken = 5;
    int arr[] = {1, 10};
    cout << minTime(arr, boards, painters, timeTaken) << endl;
    return 0;
}