#include <iostream>
#include <string>
using namespace std;

const int CHAR = 256;
bool areAnagram(string &pat, string &txt, int i)
{
    int count[CHAR] = {0};
    for (int j = 0; j < pat.length(); j++)
    {
        count[pat[j]]++;
        count[txt[i + j]]--;
    }
    for (int j = 0; j < CHAR; j++)
    {
        if (count[j] != 0)
            return false;
    }
    return true;
}

bool isPresent(string &txt, string &pat)
{
    int n = txt.length();
    int m = pat.length();
    for (int i = 0; i <= n - m; i++)
    {
        if (areAnagram(pat, txt, i))
            return true;
    }
    return false;
}

bool areSame(int CT[], int CP[])
{
    for (int i = 0; i < CHAR; i++)
        if (CT[i] != CP[i])
            return false;
    return true;
}

bool isPresentOP(string &txt, string &pat)
{
    int CT[CHAR] = {0}, CP[CHAR] = {0};
    for (int i = 0; i < pat.length(); i++)
    {
        CT[txt[i]]++;
        CP[pat[i]]++;
    }
    for (int i = pat.length(); i < txt.length(); i++)
    {
        if (areSame(CT, CP))
            return true;
        // * Sliding Window Technique
        CT[txt[i]]++;
        CT[txt[i - pat.length()]]--;
    }
    return false;
}

int main()
{
    string txt = "geeksforgeeks";
    string pat = "frog";
    cout << isPresent(txt, pat) << endl;
    cout << isPresentOP(txt, pat) << endl;

    return 0;
}