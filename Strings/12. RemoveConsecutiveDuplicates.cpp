#include <iostream>
#include <cstring>
using namespace std;

void removeDuplicates(char *str)
{
    int n = strlen(str);
    if (n < 2)
        return;
    int prev = 0;
    for (int i = 1; i < n; i++)
    {
        if (str[i] != str[prev])
            str[++prev] = str[i];
    }
    prev++;
    str[prev] = '\0';
    return;
}

int main()
{
    char s[] = "ccooooooding";
    removeDuplicates(s);
    cout << s << endl;
    return 0;
}