#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, 2, 3};
    char b[] = "abc";
    // memory address of a[0]
    cout << a << endl;

    // print the actual content
    //? this is due to cout implementation of char array
    cout << b << endl;

    //? to print address of character array
    // * Explicit Typecasting from char* to void*
    cout << (void *)b << endl;

    //* String always carries a NULL character with it
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl; // size = 4 [ as 1 for each character and 1 for null character that goes with each string ]

    char *c = &b[0];
    cout << c << endl; // prints the whole string

    char c1 = 'a';
    char *pc = &c1;

    cout << c1 << endl; // prints the actual content
    cout << pc << endl; //? first it will print the actual content then it will keep printing untill finds a NULL character

    char str[] = "abcde"; // first it will assign temporary memory and create a array and copies the content here

    // char *pstr = "abcde"; //! but here it will point to the temporary memory --- this is very Wrong!!!

    return 0;
}