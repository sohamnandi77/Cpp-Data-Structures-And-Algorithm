// ? Largest Element in the Array

#include <iostream>
using namespace std;
// Noob Method
int getLargestNoob(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n; j++)
        {
            if (a[j] > a[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return i;
    }
    return -1;
}

// OP Method
int getLargestOP(int a[], int n)
{
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[res])
        {
            res = i;
        }
    }
    return res;
}
int main()
{
    int arr[] = {5, 8, 20, 10};
    cout << "Noob Method" << endl;
    cout << getLargestNoob(arr, 4) << endl;
    cout << "OP Method" << endl;
    cout << getLargestOP(arr, 4) << endl;
    return 0;
}