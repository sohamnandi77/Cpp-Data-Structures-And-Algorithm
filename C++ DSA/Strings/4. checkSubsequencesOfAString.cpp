#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ? Time complexity - O(n)
bool checkSubseq(const string &str1, const string &str2)
{
    int m = str2.length();
    int n = str1.length();

    int j = 0;
    if (n < m)
        return false;
    for (int i = 0; i < n && j < m; i++)
    {
        if (str1[i] == str2[j])
        {
            j++;
        }
    }
    return (j == m);
}

// recursive solution
//? Time complexity -> O(n)
//! space complexity -> O(m + n) (stack space)
bool checkSubseqRecMain(const string &str1, const string &str2, int n, int m)
{
    // base cases
    //? order of bases cases matters
    if (m == 0)
        return true;
    if (n == 0)
        return false;

    if (str1[n - 1] == str2[m - 1])
        return checkSubseqRecMain(str1, str2, n - 1, m - 1);

    else
        return checkSubseqRecMain(str1, str2, n - 1, m);
}
bool checkSubseqRec(const string &str1, const string &str2)
{
    return checkSubseqRecMain(str1, str2, str1.length(), str2.length());
}

int main()
{
    string s1 = "geeksforgeeks";
    string s2 = "gfg";
    cout << checkSubseq(s1, s2) << endl;
    cout << checkSubseqRec(s1, s2) << endl;
    return 0;
}