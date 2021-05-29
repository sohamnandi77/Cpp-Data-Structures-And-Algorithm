#include <iostream>
using namespace std;

int countMazePath(int n, int i = 0, int j = 0)
{

    if (i == n - 1 || j == n - 1)
        return 1;

    if (i >= n || j >= n)
        return 0;

    return countMazePath(n, i + 1, j) + countMazePath(n, i, j + 1);
}

int main()
{
    int n = 3;
    cout << countMazePath(n) << endl;
    return 0;
}