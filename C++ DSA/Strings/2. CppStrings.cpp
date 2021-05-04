#include <iostream>
#include <string>
using namespace std;

// * Advantages
// ? Richer Library
// ? Supports operators like +,<,>,<=,>=,==
// ? can assign a string later
// ? Don't have to worry about size
// ? can also be converted t c-style strings or char array

int main()
{
    // Static
    string s1 = "hello";
    cout << s1 << endl;

    // Dynamic
    string *sp = new string;
    *sp = "def";
    cout << sp << endl;  //address of string
    cout << *sp << endl; // string
    delete sp;

    // String Input
    string s2;

    // cin >> s2; // here the problem is it will break on a space

    getline(cin, s2);
    cout << s2 << endl;

    // String Concatenation

    string s3 = s1 + s2;
    cout << s3 << endl;

    // String size
    cout << s3.size() << endl;
    cout << s3.length() << endl;

    // Substring
    cout << s3.substr(3) << endl;
    cout << s3.substr(3, 5) << endl; //slicing

    // Find
    cout << s3.find("def") << endl;

    return 0;
}