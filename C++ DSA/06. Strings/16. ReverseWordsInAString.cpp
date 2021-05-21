#include <iostream>
#include <string>
#include <stack>
using namespace std;

string revWords(string &str)
{
    stack<string> s;
    string res = "";
    int start = 0;
    for (int i = 0; i < str.length(); i++)
        if (str[i] == ' ')
        {
            s.push((str.substr(start, i - start)));
            start = i + 1;
        }
    s.push((str.substr(start, str.length() - start)));
    while (!s.empty())
    {
        res += s.top() + " ";
        s.pop();
    }
    return res;
}

void reverse(string &str, int low, int high)
{
    while (low <= high)
    {
        swap(str[low], str[high]);
        low++;
        high--;
    }
}

string revWordsOP(string &str)
{
    int start = 0;
    int n = str.length();
    for (int end = 0; end < n; end++)
    {
        if (str[end] == ' ')
        {
            reverse(str, start, end - 1);
            start = end + 1;
        }
    }
    reverse(str, start, n - 1);
    reverse(str, 0, n - 1);
    return str;
}

int main()
{
    string s = "Welcome to Gfg";
    cout << revWords(s) << endl;
    cout << revWordsOP(s) << endl;
    return 0;
}