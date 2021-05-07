//* N-bonacci numbers
#include <iostream>
using namespace std;
void nBonacci(int n, int end)
{
    // Assuming m > n.
    int *a = new int[end]{0}; // we can also use vector here
    a[n - 1] = 1;
    a[n] = 1;

    // Uses sliding window
    for (int i = n + 1; i < end; i++)
        a[i] = 2 * a[i - 1] - a[i - n - 1];

    // Printing result
    for (int i = 0; i < end; i++)
        cout << a[i] << " ";
    delete[] a;
}
int main()
{
    int N = 4, M = 12;
    nBonacci(N, M);
    return 0;
}