// ? Given an array arr[] of N positive integers, where elements are consecutive (sorted). Also, there is a single element which is repeating X (any variable) number of times. Now, the task is to find the element which is repeated and number of times it is repeated.
// Note : If there's no repeating element, Return {-1,-1}.

#include <iostream>
#include <utility>
using namespace std;

pair<int, int> findRepeating(int *arr, int n)
// # Time Complexity: O(logn)
{
    pair<int, int> p;
    p.first = -1;
    p.second = -1;
    if (arr[n - 1] - arr[0] == n - 1)
        return p;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] - arr[0] == mid)
            low = mid + 1;
        else
            high = mid - 1;
    }
    p.first = arr[high];
    p.second = n - arr[n - 1] + 1;
    return p;
}

int main()
{
    int arr[] = {1, 1, 2, 3, 4, 5};
    int size = *(&arr + 1) - arr;
    pair<int, int> res = findRepeating(arr, size);
    cout << res.first << " " << res.second << endl;
    return 0;
}