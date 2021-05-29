#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int a[] = {1, 2, 3};
    char b[] = "abc";
    // memory address of a[0]
    cout << a << endl;

    //* print the actual content
    //? this is due to cout implementation of char array
    cout << b << endl;

    //? to print address of character array
    // * Explicit Typecasting from char* to void*
    cout << (void *)b << endl;

    //* String always carries a NULL character with it
    cout << sizeof(a) << endl;
    cout << sizeof(b) << endl; // size = 4 [ as 1 for each character and 1 for null character that goes with each string ]

    char s1[] = {'a', 'b', 'c'};
    cout << s1 << endl;         // ! first it will print the actual content then it will keep printing untill finds a NULL character
    cout << sizeof(s1) << endl; // ? Size = 3 the actual size

    // -> So it is strongly recommended to always use "\0" at the end of char array

    char *c = &b[0];
    cout << c << endl; // prints the whole string

    char c1 = 'a';
    char *pc = &c1;

    cout << c1 << endl; // prints the actual content
    cout << pc << endl; //? first it will print the actual content then it will keep printing untill finds a NULL character

    char str[] = "abcde"; // first it will assign temporary memory and create a array and copies the content here

    // char *pstr = "abcde"; //! but here it will point to the temporary memory --- this is very Wrong!!!

    // Functions
    // * strlen -> returns the length of the string
    cout << strlen(str) << endl;

    // * strcmp -> compare two strings lexicographically
    char str1[] = "abc";
    char str2[] = "aba";
    cout << strcmp(str1, str2) << endl;

    // * strcpy(s1,s2) -> copies the string s2 to s1
    char str3[5];
    // ! str3 = "gfg";
    cout << strcpy(str3, "gfg") << endl;

    return 0;
}