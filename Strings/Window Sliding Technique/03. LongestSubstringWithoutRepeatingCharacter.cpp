#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int LongestSubWithoutRepeating(string &str)
{

    unordered_map<char, int> mp;
    int n = str.length();
    int i = 0, j = 0, mx = -1;
    while (j < n)
    {
        mp[str[j]]++;

        if (mp.size() == j - i + 1)
            mx = max(mx, j - i + 1);

        if (mp.size() < j - i + 1)
        {
            while (mp.size() < j - i + 1)
            {
                mp[str[i]]--;
                if (mp[str[i]] == 0)
                    mp.erase(str[i]);
                i++;
            }
        }
        j++;
    }

    return mx;
}

int main()
{
    string str = "pwwkxew";
    cout << LongestSubWithoutRepeating(str) << endl;
    return 0;
}