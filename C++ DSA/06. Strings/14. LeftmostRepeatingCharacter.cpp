#include <iostream>
#include <string>
using namespace std;
const int CHAR = 26;

int leftMostNoob(string &str)
{
    for (int i = 0; i < str.length(); i++)
        for (int j = i + 1; j < str.length(); j++)
            if (str[j] == str[i])
                return i;
    return -1;
}

int leftMostBetter(string &str)
{
    int count[CHAR] = {0};
    for (int i = 0; i < str.length(); i++)
        count[str[i] - 'a']++;
    for (int i = 0; i < str.length(); i++)
        if (count[str[i] - 'a'] > 1)
            return i;
    return -1;
}

int leftMostEfficient(string &str)
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
            res = min(res, fi);
    }
    return res == INT_MAX ? -1 : res;
}
int leftMostOP(string &str)
{
    bool visited[CHAR];
    fill(visited, visited + CHAR, false);
    int res = -1;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (visited[str[i]])
            res = i;
        else
            visited[str[i]] = true;
    }
    return res;
}

int main()
{
    string str = "bcaca";
    cout << leftMostNoob(str) << endl;
    cout << leftMostBetter(str) << endl;
    cout << leftMostEfficient(str) << endl;
    cout << leftMostOP(str) << endl;
    return 0;
}