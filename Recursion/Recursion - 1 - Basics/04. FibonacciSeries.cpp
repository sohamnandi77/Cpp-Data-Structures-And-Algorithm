#include <iostream>
using namespace std;

int fibonacci(int n) // f(n) = f(n-1) + f(n-2);
{
    // Base Case:
    if (n <= 1)
        return n;

    // Recursive Case:
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    cout << fibonacci(10) << endl;
    return 0;
}