#include <iostream>
#include <string>
using namespace std;
void subsetsOfString(string str, int index = 0, string curr = "")
{
    if (index == str.length())
    {
        cout << curr << " ";
        return;
    }
    subsetsOfString(str, index + 1, curr);
    subsetsOfString(str, index + 1, curr + str[index]);
}
int main()
{
    string str = "ABC";
    subsetsOfString(str);
    return 0;
}