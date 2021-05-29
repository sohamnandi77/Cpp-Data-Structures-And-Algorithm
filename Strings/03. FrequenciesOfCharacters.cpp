#include <iostream>
#include <string>
using namespace std;

void freq(string str)
{
    int count[52] = {0}; // first capital letters are stored the small
    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i] - 'A') <= 26)
            count[str[i] - 'A']++; // capital letters
        else
            count[str[i] - 'A' - 6]++; // small letters
    }
    for (int i = 0; i < 52; i++)
    {
        if (count[i] > 0 && (i + 'A') <= 90)
            cout << (char)(i + 'A') << " " << count[i] << endl;
        else if (count[i] > 0 && (i + 'A') > 90)
            cout << (char)(i + 'A' + 6) << " " << count[i] << endl;
    }
}

int main()
{
    string s = "geeksforgeeks";
    freq(s);
    return 0;
}