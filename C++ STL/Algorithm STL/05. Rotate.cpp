#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = *(&arr + 1) - arr;
    rotate(arr, arr + 3, arr + n);
    for (int x : arr)
        cout << x << " ";
    return 0;
}