#include <iostream>
using namespace std;

void genStrings(string input, string output = "")
{
    // base case:
    if (input.empty())
    {
        cout << output << " ";
        return;
    }

    // recursion case:
    // one digit at a time
    int digit = input[0] - '0';
    if (digit != 0)
    {
        char ch = digit + 'A' - 1;
        genStrings(input.substr(1), output + ch);
    }
    // two digit at a time
    if (input[1] != '\0')
    {
        int twoDigit = digit * 10 + (input[1] - '0');
        if (twoDigit <= 26)
        {
            char twoCh = twoDigit + 'A' - 1;
            genStrings(input.substr(2), output + twoCh);
        }
    }
    return;
}

int main()
{
    string n = "1012";
    genStrings(n);
    return 0;
}