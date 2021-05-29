#include <iostream>
#include <string>
using namespace std;

int len(char *str)
{
    if (str[0] == '\0')
        return 0;

    return 1 + len(str + 1);
}

void RemoveDuplicates(char *s)
{
    // Base Case
    if (len(s) <= 1)
        return;

    if (s[0] == s[1])
    {
        int i = 1;
        for (; s[i] != '\0'; i++)
            s[i - 1] = s[i];

        // for null character
        s[i - 1] = s[i];
        RemoveDuplicates(s);
    }
    else
        RemoveDuplicates(s + 1);
}

string removeDuplicates(string s)
{
    if (s.length() == 0)
        return "";

    char ch = s[0];
    string ans = removeDuplicates(s.substr(1));
    if (ch == ans[0])
        return ans;
    return ch + ans;
}

int main()
{
    char str[] = "aabbbcdda";
    cout << removeDuplicates(str) << endl;
    RemoveDuplicates(str);
    cout << str << endl;
    return 0;
}