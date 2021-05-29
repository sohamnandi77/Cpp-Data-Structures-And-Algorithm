#include <iostream>
#include <string>
using namespace std;

int strToInt(string str, int a)
{
    // Base Case:
    if (a == 0)
        return 0;

    // small calculations
    int digit = str[a - 1] - '0';

    // recursive case:
    int ans = strToInt(str, a - 1);
    return ans * 10 + digit;
}

int main()
{
    string str = "1234";
    int a = str.length();
    cout << strToInt(str, a) << endl;
    return 0;
}