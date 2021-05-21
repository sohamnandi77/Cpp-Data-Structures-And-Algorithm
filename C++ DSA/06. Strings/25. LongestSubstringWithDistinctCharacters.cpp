#include <bits/stdc++.h>
using namespace std;

bool areDistinct(string str, int i, int j)
{

    vector<bool> visited(256);

    for (int k = i; k <= j; k++)
    {
        if (visited[str[k]] == true)
            return false;
        visited[str[k]] = true;
    }
    return true;
}

int longestDistinctNoob(string str)
{
    int n = str.length();
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (areDistinct(str, i, j))
                res = max(res, j - i + 1);
    return res;
}

int longestDistinctBetter(string str)
{
    int n = str.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(256);
        for (int j = i; j < n; j++)
        {
            if (visited[str[j]] == true)
            {
                break;
            }
            else
            {
                res = max(res, j - i + 1);
                visited[str[j]] = true;
            }
        }
    }
    return res;
}

int longestDistinctOP(string str)
{
    int n = str.length();
    int res = 0;
    vector<int> prev(256, -1);
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        i = max(i, prev[str[j]] + 1);
        int maxEnd = j - i + 1;
        res = max(res, maxEnd);
        prev[str[j]] = j;
    }
    return res;
}

int main()
{
    string str = "geeksforgeeks";
    cout << longestDistinctNoob(str) << endl;
    cout << longestDistinctBetter(str) << endl;
    cout << longestDistinctOP(str) << endl;
    return 0;
}
