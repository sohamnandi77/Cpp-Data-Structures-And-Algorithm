#include <iostream>
using namespace std;
int ThirdLargest(int a[], int n)
{
    int first = a[0], second = INT_MIN, third = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > first)
        {
            third = second;
            second = first;
            first = a[i];
        }
        else if (a[i] > second)
        {
            third = second;
            second = a[i];
        }
        else if (a[i] > third)
        {
            third = a[i];
        }
    }
    return third;
}
int main()
{
    int arr[] = {5, 20, 8, 20, 10};
    cout << ThirdLargest(arr, 5) << endl;
    return 0;
}