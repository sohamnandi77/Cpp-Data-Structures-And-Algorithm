#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int LongestSubWithKchar(string &str, int k)
{
    unordered_map<char, int> mp;
    int n = str.length();
    int i = 0, j = 0, mx = -1;
    while (j < n)
    {
        mp[str[j]]++;

        if (mp.size() < k)
            j++;

        if (mp.size() == k)
        {
            mx = max(mx, j - i + 1);
            j++;
        }

        if (mp.size() > k)
        {
            while (mp.size() > k)
            {
                mp[str[i]]--;
                if (mp[str[i]] == 0)
                    mp.erase(str[i]);
                i++;
            }
            j++;
        }
    }

    return mx;
}

int main()
{
    string str = "aabacbebebe";
    int k = 3;
    cout << LongestSubWithKchar(str, k) << endl;
    return 0;
}