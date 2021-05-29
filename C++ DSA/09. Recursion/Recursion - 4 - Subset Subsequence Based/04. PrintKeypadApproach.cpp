#include <iostream>
using namespace std;

string words[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypadApproach(int n, string output = "")
{
    // base case:
    if (n == 0)
    {
        cout << output << " ";
        return;
    }

    int N = (n % 10) - 2;
    int len = words[N].length();

    // recursive Case:
    for (int i = 0; i < len; i++)
        keypadApproach(n / 10, words[N][i] + output);
    return;
}

int main()
{
    int input = 92;
    keypadApproach(input);
    return 0;
}