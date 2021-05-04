// Given an array a of size n such that,
// arr contains all the elements from 0 to max(a)
// only one element is repeated any number of time
// 0 <= max(a) <= n-2

#include <iostream>
using namespace std;

int findRepeatingElement(int *arr, int n)
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
    int arr[] = {0, 1, 2, 2, 4, 6, 5, 7, 3}, n = 9;

    cout << findRepeatingElement(arr, n);
    return 0;
}