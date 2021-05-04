#include <iostream>
using namespace std;
#define mod 1000000007
long long rev(long long n)
{
    long long rev_num = 0;
    while (n > 0)
    {
        rev_num = rev_num * 10 + n % 10;
        n = n / 10;
    }
    return rev_num;
}
long long Power(int n, int R)
{
    if (n == 0)
        return 0;
    if (R == 0)
        return 1;

    long long y;
    if (R % 2 == 0)
    {
        y = Power(n, R / 2);
        y = (y * y) % mod;
    }
    else
    {
        y = n % mod;
        y = (y * Power(n, R - 1) % mod) % mod;
    }

    return ((y + mod) % mod);
}
int main()
{
    int n = 12;
    int R = rev(n);
    cout << Power(n, R) << endl;
    return 0;
}