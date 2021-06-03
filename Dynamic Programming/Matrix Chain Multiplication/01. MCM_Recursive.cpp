#include <iostream>
#include <vector>
using namespace std;

// return the minimum cost of MCM
// k = i => k = j-1  --> fun(i to k) fun(k+1 to j)
// k = i+1 => k = j  --> fun(i to k-1) fun(k to j)

int MCM(int *arr, int i, int j)
{
    // Base Case:
    if (i >= j)
        return 0;

    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        // calculate temp ans
        int temp = MCM(arr, i, k) + MCM(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
        ans = min(ans, temp);
    }

    return ans;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = *(&arr + 1) - arr;
    cout << MCM(arr, 1, n - 1) << endl;
    return 0;
}