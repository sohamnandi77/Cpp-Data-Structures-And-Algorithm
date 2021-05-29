#include <iostream>
using namespace std;

int countBinaryString(int n, int k = 0)
{

    if (n == 0 || n == 1)
        return n;

    return countBinaryString(n - 1) + countBinaryString(n - 2);
}

int main()
{
    int n = 3;
    cout << countBinaryString(n) << endl;
    return 0;
}