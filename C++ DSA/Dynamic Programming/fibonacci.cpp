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

int main()
{

    return 0;
}