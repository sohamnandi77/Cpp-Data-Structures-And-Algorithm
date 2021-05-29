#include <iostream>
using namespace std;

int gameBoard(int s, int e)
{
    // Base case:
    if (s == e)
        return 1;
    if (s > e)
        return 0;

    int count = 0;
    // Recursion:
    for (int i = 1; i <= 6; i++)
        count += gameBoard(s + i, e);

    return count;
}

int main()
{
    int s = 0;
    int e = 3;
    cout << gameBoard(s, e) << endl;
    return 0;
}