#include <iostream>
using namespace std;
long long RecursivePower(int n, int p)
{
    if (p == 0)
        return 1;

    else if (p % 2 == 0)
    {
        return RecursivePower(n, p / 2) * RecursivePower(n, p / 2);
    }
    else
    {
        return n * RecursivePower(n, p / 2) * RecursivePower(n, p / 2);
    }
}
int main()
{
    cout << RecursivePower(9, 9) << endl;
    return 0;
}