#include <iostream>
using namespace std;

// # Time Complexity: O(log(max(a,b)))
int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int gcdIterative(int a, int b)
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    int a = 16, b = 10;
    cout << gcd(a, b) << endl;
    cout << gcdIterative(a, b) << endl;
    return 0;
}