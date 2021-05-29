#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int subseq(string s1, string *s2)
{
    // base case:
    if (s1.empty())
    {
        s2[0] = "";
        return 1;
    }

    // recursive case:
    int size = subseq(s1.substr(1), s2);

    // small calculations:
    for (int i = 0; i < size; i++)
        s2[i + size] = s1[0] + s2[i];
    return 2 * size;
}

int main()
{
    string input = "abc";
    string *output = new string[(int)pow(2, input.length())];

    int count = subseq(input, output);
    for (int i = 0; i < count; i++)
        cout << output[i] << " ";
    delete[] output;
    return 0;
}