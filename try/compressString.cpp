#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

void compress(string str)
{
    int len = str.length();
    unordered_map<char, int> h;
    bool count[26] = {false};
    for (int i = 0; i < len; i++)
        h[str[i]]++;
    string str2 = "";
    for (int i = 0; i < len; i++)
        if (!count[str[i] - 'a'])
        {
            str2 += str[i] + to_string(h[str[i]]);
            count[str[i] - 'a'] = true;
        }

    if (str2.length() < len)
        cout << str2 << endl;
    else
        cout << 0 << endl;
}

int main()
{
    string str = "ffillltttteeeeerreddd";
    compress(str);
    return 0;
}