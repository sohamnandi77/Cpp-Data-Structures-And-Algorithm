#include <iostream>
using namespace std;
int sumOfDigits(int n)
{
    if (n <= 10)
        return n;
    return n % 10 + sumOfDigits(n / 10);
}
int digitalRoot(int n)
{
    if (n < 10)
        return n;
    return digitalRoot(sumOfDigits(n));
}
int main()
{
    cout << digitalRoot(789) << endl;
    return 0;
}