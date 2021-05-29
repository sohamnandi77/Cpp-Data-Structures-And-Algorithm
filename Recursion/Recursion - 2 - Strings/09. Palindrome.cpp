#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string &str, int start, int end)
{
    if (start >= end)
        return true;

    return ((str[start] == str[end]) && (isPalindrome(str, start + 1, end - 1)));
}
int main()
{
    string str = "abbba";
    if (isPalindrome(str, 0, str.length() - 1) == 1)
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}