#include <iostream>
using namespace std;

int ladder(int n, int k)
{
    // Base case:
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    int count = 0;
    // Recursion:
    for (int i = 1; i <= k; i++)
        count += ladder(n - i, k);

    return count;
}

int main()
{
    int n = 4;
    int k = 3;
    cout << ladder(n, k) << endl;
    return 0;
}