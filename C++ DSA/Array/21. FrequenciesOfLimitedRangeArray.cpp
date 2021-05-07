// ? Given an array A[] of N positive integers which can contain integers from 1 to P where elements can be repeated or can be absent from the array. Your task is to count the frequency of all elements from 1 to N.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void frequencyCount(vector<int> &arr, int N, int P)
{
    //Decreasing all elements by 1 so that the elements
    //become in range from 0 to n-1.
    for (int i = 0; i < N; i++)
        arr[i] -= 1;
    sort(arr.begin(), arr.end());
    int ind = N;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] >= N)
        {
            if (ind == N)
                ind = i;
            arr[i] = 0;
        }
    }
    for (int i = 0; i < ind; i++)
        arr[arr[i] % N] += N;

    for (int i = 0; i < N; i++)
        arr[i] /= N;
}

int main()
{

    vector<int> arr = {2, 3, 2, 3, 5};
    int n = arr.size();
    int p = 5;
    frequencyCount(arr, n, p);
    for (int x : arr)
        cout << x << " ";
}