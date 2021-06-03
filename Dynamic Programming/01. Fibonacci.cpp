#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n <= 1)
        return n;

    int a = fibo(n - 1);
    int b = fibo(n - 2);
    return a + b;
}

int fiboBetter(int n, int *arr)
{
    if (n == 0 || n == 1)
        return n;
    if (arr[n] > 0)
        return arr[n];

    int output = fiboBetter(n - 1, arr) + fiboBetter(n - 2, arr);
    arr[n] = output;
    return output;
}

int fiboIter(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
        arr[i] = arr[i - 1] + arr[i - 2];

    int output = arr[n];
    delete[] arr;
    return output;
}

int main()
{
    int n = 20;
    cout << fibo(n) << endl;
    cout << fiboIter(n) << endl;

    // int *arr = new int[n];
    // cout << fiboBetter(n, arr) << endl;
    // delete[] arr;
    return 0;
}