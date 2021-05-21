// ? Rabin Karp Algorithm

// * Time Complexity: O(n)

#include <iostream>
#include <string>
using namespace std;
#define d 256
const int q = 101;

void RBSearch(string &txt, string &pat)
{
    int m = pat.length();
    int n = txt.length();

    // * Compute d^(m-1) % q
    int h = 1;
    for (int i = 1; i <= m - 1; i++)
        h = (h * d) % q;

    // * Compute p and t0
    int p = 0, t = 0;
    for (int i = 0; i < m; i++)
    {
        p = (p * d + pat[i]) % q;
        t = (t * d + txt[i]) % q;
    }

    for (int i = 0; i <= (n - m); i++)
    {
        // * Check for hit
        if (p == t)
        {
            bool flag = true;
            for (int j = 0; j < m; j++)
                if (txt[i + j] != pat[j])
                {
                    flag = false;
                    break;
                }
            if (flag == true)
                cout << i << " ";
        }
        // * Compute ti+1 using ti
        if (i < n - m)
        {
            t = ((d * (t - txt[i] * h)) + txt[i + m]) % q;
            if (t < 0)
                t += q;
        }
    }
}

int main()
{
    string txt = "ABCABCD";
    string pat = "ABCD";
    RBSearch(txt, pat);
    return 0;
}