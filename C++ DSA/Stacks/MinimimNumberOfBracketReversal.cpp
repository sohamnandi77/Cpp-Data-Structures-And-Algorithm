#include <iostream>
#include <stack>
#include <string>
using namespace std;

int bracketReversal(string str)
{
    int len = str.length();
    if (len % 2) // 0,1
        return -1;

    stack<char> s;
    int left = 0, right = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '{')
        {
            s.push(str[i]);
            left++;
            continue;
        }

        if (str[i] == '}')
            right++;

        if (!s.empty() && str[i] == '}' && s.top() == '{')
        {
            s.pop();
            left--;
            right--;
            continue;
        }
    }

    return (left + right) / 2 + right % 2;
}

int main()
{
    string str = "{}";
    cout << bracketReversal(str) << endl;
    return 0;
}