#include <iostream>
#include <string>
using namespace std;

void replacePI(char str[], int i)
{
    // base case:
    if (str[i] == '\0')
        return;

    // small calculations
    if (str[i] == 'p' && str[i + 1] == 'i')
    {
        int j = i + 2;
        while (str[j] != '\0')
            j++;
        while (j >= i + 2)
        {
            str[j + 2] = str[j];
            j--;
        }

        str[i] = '3';
        str[i + 1] = '.';
        str[i + 2] = '1';
        str[i + 3] = '4';
        replacePI(str, i + 4);
    }
    else
        replacePI(str, i + 1);
    return;
}

void replaceStringPI(string str)
{

    // Base Case:
    if (str.length() == 0)
        return;

    if (str[0] == 'p' && str[1] == 'i')
    {
        cout << "3.14";
        replaceStringPI(str.substr(2));
    }
    else
    {
        cout << str[0];
        replaceStringPI(str.substr(1));
    }
}
int main()
{
    char str[] = "xppppixxpipixp";
    replacePI(str, 0);
    cout << str << endl;
    return 0;
}