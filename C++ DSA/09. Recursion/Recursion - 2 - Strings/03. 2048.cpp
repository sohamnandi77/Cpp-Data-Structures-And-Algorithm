#include <iostream>
#include <string>
using namespace std;

string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printSpellings(int n)
{
    if (n == 0)
        return;

    printSpellings(n / 10);
    cout << words[n % 10] << " ";
}

int main()
{
    printSpellings(2048);
    return 0;
}