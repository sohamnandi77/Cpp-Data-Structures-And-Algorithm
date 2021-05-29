#include <iostream>
#include <string>
using namespace std;

string moveXtoLast(string str)
{
    if (str.length() == 0)
        return "";

    char ch = str[0];
    string ans = moveXtoLast(str.substr(1));
    if (ch == 'x')
        return ans + ch;
    else
        return ch + ans;
}

int main()
{
    string str = "axxcdxcefxhix";
    cout << moveXtoLast(str) << endl;
    return 0;
}