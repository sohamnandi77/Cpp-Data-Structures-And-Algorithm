#include <iostream>
#define ll long long
#define mod 1000000007
using namespace std;

ll int noOfBalancedtrees(int h)
{

    if (h <= 1)
        return 1;

    ll int x = noOfBalancedtrees(h - 1);
    ll int y = noOfBalancedtrees(h - 2);
    return ((x % mod * x % mod) % mod + (2 * x % mod * y % mod) % mod) % mod;
}

int main()
{
    int h = 8;
    cout << noOfBalancedtrees(h) << endl;
    return 0;
}