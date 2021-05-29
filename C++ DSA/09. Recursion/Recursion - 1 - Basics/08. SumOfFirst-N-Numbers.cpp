#include <iostream>
using namespace std;

// non - tail recursive
int sum(int n)
{
    // base case
    if (n == 0)
        return 0;
    // recursive call
    return n + sum(n - 1);
}

// tail recursive
int sum(int n, int k)
{
    // base case
    if (n == 0)
        return k;
    // recursive call
    return sum(n - 1, k + n);
}

int main()
{
    cout << "Non Tail Recursive" << endl;
    cout << sum(100) << endl;
    cout << "Tail Recursive" << endl;
    cout << sum(100, 0) << endl;
    return 0;
}