// * Time Complexity: O((m+n-1)*m)

#include <iostream>
#include <string>
using namespace std;

void naiveSearch(string &txt, string &pat)
{
    int m = pat.length();
    int n = txt.length();
    for (int i = 0; i <= (n - m); i++)
    {
        int j;
        for (j = 0; j < m; j++)
            if (pat[j] != txt[i + j])
                break;

        if (j == m)
            cout << i << " ";
    }
}

int main()
{
    string txt = "ABCABCD";
    string pat = "ABCD";
    naiveSearch(txt, pat);
    return 0;
}