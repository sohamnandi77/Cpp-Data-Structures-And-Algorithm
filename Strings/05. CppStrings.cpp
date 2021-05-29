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
    string s0;
    cout << s0 << endl; // -> empty string

    string s1("hello");
    cout << s1 << endl; // -> hello

    string s2 = "hello";
    cout << s2 << endl; // -> hello

    string s3(s2);
    cout << s3 << endl; // -> hello

    string s4 = s3;
    cout << s3 << endl; // -> hello

    char a[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    string s5(a);
    cout << s5 << endl; // -> hello

    char b[] = {'h', 'e', 'l', 'l', 'o'};
    string s6(b);       // ! Never pass non-null terminated arrays to strings.
    cout << s6 << endl; // -> hello...garbage

    // Dynamic
    string *sp = new string;
    *sp = "def";
    cout << sp << endl;  //address of string
    cout << *sp << endl; // string
    delete sp;

    // String Input
    string str;

    // cin >> s2; // here the problem is it will break on a space

    getline(cin, str);
    cout << str << endl;
    // -> getline (cin, str, 'a'); it has a extra parameter which we can pass to tell where to break

    // Iterate over all the charater
    // for loop
    for (int i = 0; i < str.length(); i++)
        cout << str << " ";
    cout << endl;

    //* using iterators
    for (auto it = str.begin(); it != str.end(); it++)
        cout << (*it) << " ";
    cout << endl;

    //* for each look
    for (auto x : str)
        cout << x << " ";
    cout << endl;

    // String Concatenation
    string str3 = s1 + str;
    cout << str3 << endl;
    str3.append("gfg");
    cout << str3 << endl;

    // String size
    // * Both returns the actual size
    cout << str3.size() << endl;
    cout << str3.length() << endl;

    // Substring
    cout << str3.substr(3) << endl;
    cout << str3.substr(3, 5) << endl; //slicing

    // Find -> return the index of the first occurrences of a string
    // * if not found it returns a special constant -> string::npos
    string word = "adad";
    int idx = str3.find(word) == string::npos ? -1 : str3.find(word);
    cout << idx << endl;

    // Remove
    cout << str3.length() << endl;
    try
    {
        str3.erase(idx, str.length()); // ! don't use it unless sure that u will get a index and a length
    }
    catch (const std::exception &e)
    {
        cerr << e.what() << '\n';
    }

    cout << str3.length() << endl;
    str3.clear();
    cout << str3.length() << endl;

    // compare

    cout << s1.compare(s2) << endl;
    if (s1 < s2)
        cout << "Smaller" << endl;
    if (s1 > s2)
        cout << "Greater" << endl;
    if (s1 == s2)
        cout << "Equal" << endl;

    return 0;
}