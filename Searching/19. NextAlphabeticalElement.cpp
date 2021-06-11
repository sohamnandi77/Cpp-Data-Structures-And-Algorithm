#include <iostream>
#include <string>
using namespace std;

char nextElement(string &str, char s)
{

    // Your code here
    char low = 0, high = str.length() - 1, res;
    while (low <= high)
    {
        char mid = high + (low - high) / 2;

        if (str[mid] <= s)
            low = mid + 1;
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
    return str[res];
}

int main()
{
    string str = "acfh";
    char s = 'f';
    cout << nextElement(str, s) << endl;

    return 0;
}