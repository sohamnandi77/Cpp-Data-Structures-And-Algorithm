#include <iostream>
using namespace std;

//* array in function pass as a pointer so their size will be 4
int sizeOfArray(int a[], int size)
{
    // return sizeof(a);
    return 0;
}

// So we will pass array just as a pointer
int sumOfArray(int *a, int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans += a[i];
    }
    return ans;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sizeof(a) << endl;          // 40
    cout << sizeOfArray(a, 10) << endl; // 8 as arrays are passed to functions as pointers
    cout << sumOfArray(a, 10) << endl;

    // We can also pass a part of array to the function
    cout << sumOfArray(a - 3, 7) << endl;
    return 0;
}