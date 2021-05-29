#include <iostream>
using namespace std;

int friendsPairing(int n)
{
    // Base case:
    if (n == 0 || n == 1 || n == 2)
        return n;

    // Recursive case:
    return 1 * friendsPairing(n - 1) + (n - 1) * friendsPairing(n - 2);
}

int main()
{
    int n = 3;
    cout << friendsPairing(4) << endl;
    return 0;
}