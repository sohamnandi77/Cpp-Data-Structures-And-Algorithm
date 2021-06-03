#include <iostream>
using namespace std;

int LCS(string x, string y, int n, int m)
{
    // base case:
    if (n == 0 || m == 0)
        return 0;

    // recursive case:
    // # if last string matchs, exclude the last letter of both
    if (x[n - 1] == y[n - 1])
        return 1 + LCS(x, y, n - 1, m - 1);

    // # two choices:
    // -> Remove the last letter of 1st string and keep the other.
    // -> Remove the last letter of 2nd string and keep the other.
    return max(LCS(x, y, n, m - 1), LCS(x, y, n - 1, m));
}

int main()
{
    string x = "abcdgh";
    string y = "abedfh";
    cout << LCS(x, y, x.length(), y.length()) << endl;
    return 0;
}