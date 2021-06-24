#include <iostream>
#include <string>
using namespace std;

void sumArray(int *arr1, int *arr2, int n1, int n2)
{
    int a = 0, b = 0;
    for (size_t i = 0; i < n1; i++)
    {
        a *= 10;
        a += arr1[i];
    }
    for (size_t i = 0; i < n2; i++)
    {
        b *= 10;
        b += arr2[i];
    }

    a += b;
    for (auto x : to_string(a))
        cout << x << " ";
}

int main()
{
    int arr1[] = {1, 0, 2, 9};
    int n1 = *(&arr1 + 1) - arr1;
    int arr2[] = {3, 4, 5, 6, 7};
    int n2 = *(&arr2 + 1) - arr2;
    sumArray(arr1, arr2, n1, n2);
    return 0;
}