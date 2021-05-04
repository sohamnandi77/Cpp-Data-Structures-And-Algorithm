#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool BalancedParenthesis(string str)
{
    stack<char> s;
    char x;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            s.push(str[i]);
            continue;
        }

        // IF current current character is not opening bracket, then it must be closing. So stack cannot be empty at this point.

        if (s.empty())
            return false;

        switch (str[i])
        {
        case ')':
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;
        case ']':
            x = s.top();
            s.pop();
            if (x == '{' || x == '(')
                return false;
            break;
        case '}':
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;
        }
    }

    return (s.empty());
}

int main()
{
    string str = "({[]}";
    if (BalancedParenthesis(str))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}