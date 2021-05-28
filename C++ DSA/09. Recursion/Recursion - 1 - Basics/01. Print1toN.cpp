#include <iostream>
using namespace std;
//? non tail recursive
void print1toN(int n)
{
    // Base Condition
    if (n == 0)
        return;

    // Recursive call
    print1toN(n - 1);
    cout << n << endl;
}

//? tail recursive
//* Tail recursive are a bit faster than  non-tail recursive in modern compilers
void print1toN(int n, int k)
{
    // Base Condition
    if (n == 0)
    {
        return;
    }
    // Recursive call
    cout << k << endl;
    print1toN(n - 1, k + 1);
}
int main()
{
    cout << "Non Tail Recursive" << endl;
    print1toN(5);
    cout << "Tail Recursive" << endl;
    print1toN(5, 1);
    return 0;
}
