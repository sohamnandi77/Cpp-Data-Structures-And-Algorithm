#include <iostream>
using namespace std;
int main()
{
    int i = 10;
    int *p = &i;

    cout << p << endl;
    cout << *p << endl;

    p += 1; // it adds 4 to the hexadecimal address (size of int)

    cout << p << endl;
    cout << *p << endl;

    double d = 102.3;
    double *dp = &d;

    cout << dp << endl;
    dp++; // it adds 8 to the hexadecimal address (size fo double)
    cout << dp << endl;
    return 0;
}
