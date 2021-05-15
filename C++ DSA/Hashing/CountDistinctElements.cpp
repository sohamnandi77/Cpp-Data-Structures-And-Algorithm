#include <iostream>
#include <unordered_set>
using namespace std;

int countDistinctElements(int *arr, int n)
{
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);
    return s.size();
}

int countDistinctElementsImprove(int *arr, int n)
{
    unordered_set<int> s(arr, arr + n);
    return s.size();
}

int main()
{
    int arr[] = {10, 20, 10, 30, 50, 30, 20};
    int size = *(&arr + 1) - arr;
    cout << countDistinctElements(arr, size) << endl;
    cout << countDistinctElementsImprove(arr, size) << endl;
    return 0;
}