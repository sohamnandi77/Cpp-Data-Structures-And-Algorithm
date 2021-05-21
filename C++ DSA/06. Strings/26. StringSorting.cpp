#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

bool lexioCompare(pair<string, string> a, pair<string, string> b)
{
    return a.second < b.second;
}
bool numericCompare(pair<string, string> a, pair<string, string> b)
{
    return stoi(a.second) < stoi(b.second);
}

string extractToken(string &str, int key)
{
    int i;
    char *res = strtok((char *)str.c_str(), " ");
    while (key > 1)
    {
        res = strtok(NULL, " ");
        key--;
    }
    return (string)res;
}

int main()
{
    int n;
    cin >> n;
    cin.get();

    string str[100];
    for (int i = 0; i < n; i++)
        getline(cin, str[i]);
    int key = 1;
    string reversal = "true", ordering = "numeric";

    pair<string, string> strPair[100];
    for (int i = 0; i < n; i++)
    {
        strPair[i].first = str[i];
        strPair[i].second = extractToken(str[i], key);
    }

    // Next = sorting
    if (ordering == "numeric")
        sort(strPair, strPair + n, numericCompare);
    else
        sort(strPair, strPair + n, lexioCompare);

    // Reversal
    if (reversal == "true")
    {
        for (int i = 0; i < n / 2; i++)
            swap(strPair[i], strPair[n - i - 1]);
    }

    // Print the output
    for (int i = 0; i < n; i++)
        cout << strPair[i].first << endl;
    return 0;
}