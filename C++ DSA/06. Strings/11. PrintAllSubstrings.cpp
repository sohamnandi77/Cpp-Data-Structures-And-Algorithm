#include <iostream>
#include <string>
using namespace std;

void printSubstrings(string &str)
{
    for (int i = 0; i < str.length(); i++)
        for (int j = i; j < str.length(); j++)
        {
            for (int k = i; k <= j; k++)
                cout << str[k];
            cout << endl;
        }
}

int main()
{
    string s = "abc";
    printSubstrings(s);
    return 0;
}