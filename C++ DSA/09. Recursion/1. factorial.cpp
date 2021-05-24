#include <iostream>
using namespace std;
int factorial(int n)
{
    //* Base Case or Stopping condition
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
int main()
{
    int n;
    cin >> n;
    int output = factorial(n);
    cout << output << endl;
    return 0;
}