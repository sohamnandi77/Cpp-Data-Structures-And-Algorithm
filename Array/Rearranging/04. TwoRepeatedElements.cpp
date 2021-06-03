// ? You are given an array of N+2 integer elements. All elements of the array are in range 1 to N. Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoRepeated(int arr[], int n)
// # Time Complexity: O(n)
// * Scaleable but at most 2 duplicate elements
{
    vector<int> p;
    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i])] < 0)
            p.push_back(abs(arr[i]));
        else
            arr[abs(arr[i])] = -arr[abs(arr[i])];
    }
    return p;
}

vector<int> twoRepeatedOP(int *arr, int n)
// # Time Complexity: O(n)
{
    vector<int> p;
    for (int i = 0; i < n; i++)
    {
        arr[((arr[i] % n) - 1)] += n;
        if (arr[((arr[i] % n) - 1)] / n == 2)
            p.push_back(((arr[i] % n) - 1) + 1);
    }
    return p;
}

int main()
{
    int arr[] = {1, 2, 1, 3, 4, 3};
    int n = *(&arr + 1) - arr;
    vector<int> res = twoRepeated(arr, n);
    for (int x : res)
        cout << x << " ";
    // vector<int> res = twoRepeatedOP(arr, n);
    // for (int x : res)
    //     cout << x << " ";
    return 0;
}