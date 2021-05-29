#include <iostream>
#include <string>
using namespace std;

void genBalancedBrackets(int n, int idx = 0, string output = "", int open = 0, int close = 0)
{

    if (idx == 2 * n)
    {
        cout << output << endl;
        return;
    }

    if (open < n)
    {
        genBalancedBrackets(n, idx + 1, output + '(', open + 1, close);
    }
    if (close < open)
    {
        genBalancedBrackets(n, idx + 1, output + ')', open, close + 1);
    }
    return;
}

int main()
{
    int n = 5;
    genBalancedBrackets(n);
    return 0;
}