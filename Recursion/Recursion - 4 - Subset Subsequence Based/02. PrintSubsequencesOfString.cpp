#include <iostream>
using namespace std;

void printSubseq(string input, string output = "")
{
    // base case:
    if (input.empty())
    {
        cout << output << " ";
        return;
    }
    printSubseq(input.substr(1), output);
    printSubseq(input.substr(1), output + input[0]);
}

int main()
{
    string input = "abc";
    printSubseq(input);

    return 0;
}