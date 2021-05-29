#include <iostream>
#include <string>
using namespace std;

void reverse(string &s, int low, int high)
{
    while (low <= high)
        swap(s[low++], s[high--]);
}

void lRotateByDplaces(string &str, int d)
{
    reverse(str, 0, d - 1);
    reverse(str, d, str.length() - 1);
    reverse(str, 0, str.length() - 1);
}

int main()
{
    string str = "geeksforgeeks";
    lRotateByDplaces(str, 2);
    cout << str << endl;
    return 0;
}