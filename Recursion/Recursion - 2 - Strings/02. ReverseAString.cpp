#include <iostream>
using namespace std;

void reverse(char *str)
{
    if (str[0] == '\0')
        return;

    reverse(str + 1);
    cout << str[0];
}

int main()
{
    char str[] = "Hello";
    reverse(str);
    return 0;
}