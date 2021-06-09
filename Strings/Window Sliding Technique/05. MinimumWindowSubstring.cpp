#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int minWindowSub(string &str, string &pat)
{
    int n = str.length();

    unordered_map<char, int> mp;
    for (auto i : pat)
        mp[i]++;

    int count = mp.size();
    int j = 0, i = 0, res = INT_MAX;
    int maxEnd = 0, maxStart = 0; // to track the lngth of substring

    while (j < n)
    {
        if (mp.find(str[j]) != mp.end())
        {
            mp[str[j]]--;
            if (mp[str[j]] == 0)
                count--;
        }

        while (count == 0)
        {
            if (res > j - i + 1)
            {
                res = j - i + 1;
                maxStart = i;
                maxEnd = j + 1;
            }

            if (mp.find(str[i]) != mp.end())
            {
                mp[str[i]]++;
                if (mp[str[i]] > 0)
                    count++;
            }
            i++;
        }
        j++;
    }
    cout << str.substr(maxStart, maxEnd) << endl;
    return res; // Minimum Window Substring
}

int main()
{
    string str = "ADOBECODEBANC";
    string pat = "ABC";
    cout << minWindowSub(str, pat) << endl;
    return 0;
}