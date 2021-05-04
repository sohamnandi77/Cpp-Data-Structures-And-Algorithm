#include <iostream>
using namespace std;
int fibonacciSeries(int n)
{
    // Base Case
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return fibonacciSeries(n - 1) + fibonacciSeries(n - 2);
}
int main()
{
    cout << fibonacciSeries(6) << endl;
    return 0;
}