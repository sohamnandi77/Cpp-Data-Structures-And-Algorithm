#include <iostream>
using namespace std;
int main()
{
    int i = 10;
    cout << &i << endl; //* Display address of i

    int *p = &i; //* Pointers Pointers store address of variables or a memory location.

    cout << p << endl;
    cout << *p << endl; //* dereferencing

    cout << sizeof(p) << endl; //* 8 or 4

    //? generally 8 for 64 bit & 4 for 32 bit , but not confirmed

    // * Changes will be reflected on both by changing either of them
    cout << i << endl;
    cout << *p << endl;

    i++;
    cout << i << endl;
    cout << *p << endl;

    *p = 11;
    cout << i << endl;
    cout << *p << endl;

    // * Here a is completely different storage; changing a will not be affecting p or i
    int a = i;
    a++;
    cout << a << endl;
    cout << i << endl;
    cout << *p << endl;

    // ? *p can treated same as integer
    (*p)++;
    cout << i << endl;
    cout << *p << endl;

    // * But creating an alias of p will be affecting p and i
    int *q = p;
    (*q)++;
    cout << *q << endl;
    cout << *p << endl;
    cout << i << endl;

    return 0;
}