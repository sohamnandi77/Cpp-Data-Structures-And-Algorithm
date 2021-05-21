#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3};
    int n = *(&arr + 1) - arr;
    next_permutation(arr, arr + n);
    for (int x : arr)
        cout << x << " ";

    cout << endl;
    next_permutation(arr, arr + n);
    for (int x : arr)
        cout << x << " ";
    return 0;
}