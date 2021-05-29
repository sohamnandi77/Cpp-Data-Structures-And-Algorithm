#include <iostream>
#include <string>
using namespace std;

void genSubsASCII(string str, string output = "")
{
    if (str.empty())
    {
        cout << output << endl;
        return;
    }

    genSubsASCII(str.substr(1), output);
    genSubsASCII(str.substr(1), output + str[0]);
    genSubsASCII(str.substr(1), output + to_string((int)str[0]));
}

int main()
{
    string str = "AB";
    genSubsASCII(str);
    return 0;
}