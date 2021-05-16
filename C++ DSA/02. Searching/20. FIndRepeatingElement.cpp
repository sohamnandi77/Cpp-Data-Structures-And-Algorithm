// Given an array a of size n such that,
// arr contains all the elements from 0 to max(a)
// only one element is repeated any number of time
// 0 <= max(a) <= n-2

#include <iostream>
using namespace std;

int findRepeatingElementSpace(int *arr, int n)
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

int findRepeatingElementOP(int *arr, int n)
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

int main()
{
    int arr[] = {0, 1, 2, 7, 4, 6, 5, 7, 3}, n = 9;

    cout << "Space Solution" << endl;
    cout << findRepeatingElementSpace(arr, n) << endl;
    cout << "OP Solution" << endl;
    cout << findRepeatingElementOP(arr, n) << endl;
    return 0;
}