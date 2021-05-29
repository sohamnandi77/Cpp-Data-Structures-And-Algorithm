#include <iostream>
using namespace std;

// This method is Inefficient
long long RecursivePower(int n, int p)
{
    if (p == 0)
        return 1;

    else if (p % 2 == 0)
        return RecursivePower(n, p / 2) * RecursivePower(n, p / 2);
    else
        return n * RecursivePower(n, p / 2) * RecursivePower(n, p / 2);
}

long long FastPower(int n, int p)
{
    if (p == 0)
        return 1;
    int ans = RecursivePower(n, p / 2);
    ans *= ans;
    if (p % 2 != 0)
        return n * RecursivePower(n, p / 2);
    return ans;
}

int main()
{
    cout << RecursivePower(10, 4) << endl;
    return 0;
}