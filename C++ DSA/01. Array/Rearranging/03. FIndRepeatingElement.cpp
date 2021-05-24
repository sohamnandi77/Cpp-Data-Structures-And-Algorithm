// Given an array a of size n such that,
// arr contains all the elements from 0 to max(a)
// only one element is repeated any number of time
// 0 <= max(a) <= n-2

#include <iostream>
using namespace std;

int findRepeatingElementSpace(int *arr, int n)
// # Time Complexity: O(n)
// -> Space Complexity: O(n)
// * Can find left most first occurring duplicate
{
    bool *BoolArray = new bool[n - 1]{false};
    for (int i = 0; i < n; i++)
    {
        if (BoolArray[arr[i]])
            return arr[i];
        BoolArray[arr[i]] = true;
    }
    delete[] BoolArray;
    return -1;
}

int findRepeatingElementBetter(int *arr, int n)
// # Time Complexity: O(n)
// -> Space Complexity: O(1)
// * Can find left most first occurring duplicate
// ! But not scaleable
{
    int slow = arr[0] + 1, fast = arr[0] + 1; //? why we increase slow and fast by 1? => as to avoid unncessary self loop of 0 {0,2,1,2} or (0 and 1) {1,0,2,2}
    do
    {
        slow = arr[slow] + 1;
        fast = arr[arr[fast] + 1] + 1;
    } while (slow != fast);

    slow = arr[0] + 1;
    while (slow != fast)
    {
        slow = arr[slow] + 1;
        fast = arr[fast] + 1;
    }
    return slow - 1;
}

int findRepeatingElementOP(int *arr, int n)
// # Time Complexity: O(n)
// -> Space Complexity: O(1)
// * Can find left most first occurring duplicate
// * Scaleable but at most 2 duplicate elements
{

    for (int i = 0; i < n; i++)
        arr[i]++;
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i])] > 0)
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        else
        {
            // cout << abs(arr[i]) - 1 << endl;
            return abs(arr[i]) - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {0, 1, 6, 2, 4, 5, 7, 3, 4, 6};
    int n = *(&arr + 1) - arr;

    cout << "Space Solution" << endl;
    cout << findRepeatingElementSpace(arr, n) << endl;
    cout << "Better Solution" << endl;
    cout << findRepeatingElementBetter(arr, n) << endl;
    cout << "OP Solution" << endl;
    cout << findRepeatingElementOP(arr, n) << endl;
    return 0;
}