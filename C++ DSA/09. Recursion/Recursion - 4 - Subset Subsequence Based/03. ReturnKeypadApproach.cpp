#include <iostream>
using namespace std;

string words[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypadApproach(int n, string *str)
{
    // base case:
    if (n == 0)
    {
        str[0] = "";
        return 1;
    }

    // recursive Case:
    int size = keypadApproach(n / 10, str);

    int N = (n % 10) - 2;
    int len = words[N].length();

    // small calculations:
    for (int i = 0; i < len - 1; i++)
        for (int j = 0; j < size; j++)
            str[j + ((i + 1) * size)] = str[j] + words[N][i + 1];
    for (int j = 0; j < size; j++)
        str[j] += words[N][0];

    return len * size;
}

int main()
{
    int input = 92;
    string *output = new string[1000];
    int count = keypadApproach(input, output);
    for (int i = 0; i < count; i++)
        cout << output[i] << " ";
    delete[] output;
    return 0;
    return 0;
}