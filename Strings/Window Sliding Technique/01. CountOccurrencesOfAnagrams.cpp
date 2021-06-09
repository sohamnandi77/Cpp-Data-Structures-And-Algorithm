#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int countAnagrams(string &str, string &str2)
{

    // calculations
    int n = str.length();
    int k = str2.length(); // window size

    unordered_map<char, int> mp;
    for (auto i : str2)
        mp[i]++;

    int count = mp.size();
    int j = 0, i = 0, res = 0;

    while (j < n)
    {

        if (mp.find(str[j]) != mp.end())
        {
            mp[str[j]]--;
            if (mp[str[j]] == 0)
                count--;
        }

        if (j - i + 1 < k)
            j++;

        else if (j - i + 1 == k)
        {
            // Calculating Answer
            if (count == 0)
                res++;

            // Slide the Window
            if (mp.find(str[i]) != mp.end())
            {
                mp[str[i]]++;
                if (mp[str[i]] > 0)
                    count++;
            }
            i++;
            j++;
        }
    }

    return res;
}

int main()
{
    string str = "forxxorfxdofr";
    string str2 = "for";

    cout << countAnagrams(str, str2) << endl;

    return 0;
}