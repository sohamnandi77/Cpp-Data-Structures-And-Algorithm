#include <iostream>
#include <string>
using namespace std;

// void subsetsOfString(string str, int index = 0, string curr = "")
// {
//     if (index == str.length())
//     {
//         cout << curr << " ";
//         return;
//     }
//     subsetsOfString(str, index + 1, curr);
//     subsetsOfString(str, index + 1, curr + str[index]);
// }

void subsetsOfString(string str, string curr = "")
{
    if (str.empty())
    {
        cout << curr << " ";
        return;
    }
    subsetsOfString(str.substr(1), curr);
    subsetsOfString(str.substr(1), curr + str[0]);
}
int main()
{
    string str = "ABC";
    subsetsOfString(str);
    return 0;
}