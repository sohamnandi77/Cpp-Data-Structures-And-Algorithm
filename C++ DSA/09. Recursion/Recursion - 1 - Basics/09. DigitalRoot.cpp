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

int digitalRoot2(int n)
{
    // base case:
    if (n < 10)
        return n;

    // recursive case:
    int ans = n % 10 + digitalRoot2(n / 10);

    // small calculations
    if (ans < 10)
        return ans;
    else
        return digitalRoot2(ans);
}

int main()
{
    cout << digitalRoot(789) << endl;
    cout << digitalRoot2(789) << endl;
    return 0;
}