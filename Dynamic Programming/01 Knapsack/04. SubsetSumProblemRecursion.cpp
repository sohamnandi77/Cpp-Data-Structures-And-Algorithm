#include <iostream>
#include <vector>
using namespace std;

// * 0/1 knapsack similarities
// # arr[] -> weight[]
// # sum -> W

bool isSubset(int *arr, int n, int sum)
{

    // base case:
    if (n == 0 && sum > 0)
        return false;
    if (n >= 0 && sum == 0)
        return true;

    // vector<vector<int>> matrix(n + 1, vector<int>(sum + 1, 0));

    // recursive Case:
    if (arr[n - 1] <= sum)
    {
        bool exc = isSubset(arr, n - 1, sum);              // excluded
        bool inc = isSubset(arr, n - 1, sum - arr[n - 1]); //included
        return inc || exc;
    }
    else
        return isSubset(arr, n - 1, sum); // excluded
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    int n = *(&arr + 1) - arr;
    int sum = 14;
    cout << isSubset(arr, n, sum) << endl;
    return 0;
}