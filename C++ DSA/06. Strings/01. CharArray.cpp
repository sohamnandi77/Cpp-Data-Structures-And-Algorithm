#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    // c style strings
    char str[] = "gfg";
    cout << str << endl;
    cout << sizeof(str) << endl;

    // char array
    char str2[] = {'a', 'b', 'c'};
    cout << str2 << endl; // it will keep on printing untill finds a \0
    cout << sizeof(str2) << endl;

    // to tackle above problem
    char str3[] = {'a', 'b', 'c', '\0'};
    cout << str3 << endl;
    cout << sizeof(str3) << endl;

    // char array functions
    // strlen
    cout << strlen(str) << endl;

    // strcmp
    int res = strcmp(str, str3);
    if (res > 0)
        cout << "Greater" << endl;
    else if (res < 0)
        cout << "Smaller" << endl;
    else
        cout << "same" << endl;

    // strcpy
    char str4[5];
    // ! str4 ="gfg";
    strcpy(str4, "gfg");
    cout << str4 << endl;

    return 0;
}