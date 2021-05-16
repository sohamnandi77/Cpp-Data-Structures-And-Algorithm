#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check_palindromeNoob(string str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    return (rev == str);
}

bool check_palindromeOP(string str)
{
    int start = 0;
    int end = str.length() - 1;
    while (start < end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int main()
{
    string str = "abdba";
    cout << check_palindromeNoob(str) << endl;
    cout << check_palindromeOP(str) << endl;
    return 0;
}