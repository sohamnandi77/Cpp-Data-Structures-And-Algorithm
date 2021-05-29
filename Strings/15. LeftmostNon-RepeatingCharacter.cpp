#include <iostream>
#include <string>
using namespace std;
const int CHAR = 26;
int leftMostNoob(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        bool flag = false;
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[j] == str[i])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            return i;
    }
    return -1;
}

int leftMostBetter(string &str)
{
    int count[CHAR] = {0};
    for (int i = 0; i < str.length(); i++)
        count[str[i] - 'a']++;
    for (int i = 0; i < str.length(); i++)
        if (count[str[i] - 'a'] == 1)
            return i;
    return -1;
}

int leftMostOP(string &str)
{
    int count[CHAR] = {0};
    fill(count, count + CHAR, -1);
    int res = INT_MAX;
    for (int i = 0; i < str.length(); i++)
    {
        int fi = count[str[i] - 'a'];
        if (fi == -1)
            count[str[i] - 'a'] = i;
        else
            count[str[i] - 'a'] = -2;
    }
    for (int i = 0; i < CHAR; i++)
        if (count[i] >= 0)
            res = min(res, count[i]);
    return res == INT_MAX ? -1 : res;
}

int main()
{
    string str = "bcaca";
    cout << leftMostNoob(str) << endl;
    cout << leftMostBetter(str) << endl;
    cout << leftMostOP(str) << endl;
    return 0;
}