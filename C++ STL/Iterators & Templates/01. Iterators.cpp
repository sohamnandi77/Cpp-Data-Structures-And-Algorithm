#include <iostream>
#include <vector>
using namespace std;

// # Iterator are not pointers.
// * Vector Iterator can be referred as pointer as we can do pointer Arithmetic on them

int main()
{
    vector<int> v = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    vector<int>::iterator i = v.begin();
    // auto i = v.begin();
    cout << (*i) << endl;
    i++;
    cout << (*i) << endl;

    i = next(i);
    cout << (*i) << endl;

    i = next(i, 2); //* it returns an iterator
    cout << (*i) << endl;

    i = prev(i);
    cout << (*i) << endl;

    i = prev(i, 2);
    cout << (*i) << endl;

    advance(i, 3); //* it is bit different from next() as it modify the same itertor where as next() returns an iterator
    cout << (*i) << endl;

    i = v.end(); //* end points of the memory location of next pointer at the end of container

    cout << (*i) << endl; // gives garbage
    i--;
    cout << (*i) << endl;

    return 0;
}