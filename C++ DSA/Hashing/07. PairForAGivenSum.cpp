#include <iostream>
#include <unordered_set>
using namespace std;

bool isPair(int *arr, int n, int sum)
{
    unordered_set<int> s;
    s.insert(arr[0]);
    for (int i = 1; i < n; i++)
        if (s.find(sum - arr[i]) != s.end())
            return true;
        else
            s.insert(arr[i]);
    return false;
}

int main()
{
    int arr[] = {3, 8, 4, 7, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 14;
    cout << isPair(arr, n, X);
    return 0;
}