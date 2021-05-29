#include <iostream>
using namespace std;

void printPer(string str, string output = "")
{
    if (str.empty())
    {
        cout << output << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++)
        printPer(str.substr(0, i) + str.substr(i + 1), output + str[i]);
    return;
}

int main()
{
    string str = "ABC";
    printPer(str);
    return 0;
}