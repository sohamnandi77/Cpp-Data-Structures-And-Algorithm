#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

ll minNum(ll n)
{
    ll d = floor(log10(n) + 1);
    ll s = 0, j = 1;
    for (int i = 1; i <= d; i++)
    {
        if (i == d && n == 9)
            s += 9 * j;
        else
            s += (min(n % 10, 9 - (n % 10))) * j;
        n /= 10;
        j *= 10;
    }
    return s;
}

int main()
{
    ll n = 9871;
    cout << minNum(n) << endl;
    return 0;
}