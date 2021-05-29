// ? Smallest Element in the Array

#include <iostream>
using namespace std;
int getSmallestOP(int a[], int n)
{
    int res = INT_MAX;
    for (int i = 1; i < n; i++)
        if (a[i] < a[res])
            res = i;
    return res;
}

int main()
{
    int arr[] = {5, 8, 20, 10, 12, 45};
    int size = *(&arr + 1) - arr;
    cout << "OP Method" << endl;
    cout << getSmallestOP(arr, size) << endl;
    return 0;
}