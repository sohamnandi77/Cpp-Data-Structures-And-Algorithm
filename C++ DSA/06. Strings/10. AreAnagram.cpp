#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// ? If two strings are permuttions of each other then they are Anagrams.
// listen and silent are Anagrams of each other
bool areAnagramNoob(string &str1, string &str2)
// * Time Complexity: O(nlogn)
{
    if (str1.length() != str2.length())
        return false;
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

bool areAnagramOP(string &str1, string &str2)
{
    if (str1.length() != str2.length())
        return false;
    int count[26] = {0};
    for (int i = 0; i < str1.length(); i++)
    {
        count[str1[i] - 'a']++;
        count[str2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
        if (count[i] != 0)
            return false;

    return true;
}

int main()
{
    string str1 = "abaac";
    string str2 = "aacba";
    cout << areAnagramNoob(str1, str2) << endl;
    cout << areAnagramOP(str1, str2) << endl;
    return 0;
}