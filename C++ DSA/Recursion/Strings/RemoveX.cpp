#include <iostream>
using namespace std;
void removeX(char *str)
{
    // Base Case
    if (str[0] == '\0')
        return;

    if (str[0] != 'x')
    {
        removeX(str + 1);
    }
    else
    {
        int i = 1;
        for (; str[i] != '\0'; i++)
        {
            str[i - 1] = str[i];
        }
        // for null character
        str[i - 1] = str[i];
        removeX(str); // we have reduce the length of the string
    }
}
int main()
{
    char str[100] = "Hxellxo";
    removeX(str);
    cout << str << endl;

    return 0;
}