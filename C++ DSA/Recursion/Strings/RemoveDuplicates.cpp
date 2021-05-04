#include <iostream>
using namespace std;

int len(char *str)
{
    if (str[0] == '\0')
    {
        return 0;
    }

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
        {
            s[i - 1] = s[i];
        }
        // for null character
        s[i - 1] = s[i];
        RemoveDuplicates(s);
    }
    else
    {
        RemoveDuplicates(s + 1);
    }
}
int main()
{
    char str[100] = "aabbbcdda";
    RemoveDuplicates(str);
    cout << str << endl;
    return 0;
}