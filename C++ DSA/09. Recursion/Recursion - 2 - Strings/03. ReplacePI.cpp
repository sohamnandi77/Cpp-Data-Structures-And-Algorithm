#include <iostream>
#include <cstring>
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

        for (int k = j; k >= i + 2; k--)
            str[k + 2] = str[k];

        str[i] == '3';
        str[i + 1] = '.';
        str[i + 2] = '1';
        str[i + 3] = '4';
        replacePI(str, i + 4);
    }
    else
        replacePI(str, i + 1);

    return;
}

int main()
{
    char str[] = "hpiellpio";
    replacePI(str, 0);
    cout << str << endl;
    return 0;
}