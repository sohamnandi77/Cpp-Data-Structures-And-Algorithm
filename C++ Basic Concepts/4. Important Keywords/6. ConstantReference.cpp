#include <iostream>
using namespace std;
int main()
{
    //? constant reference from a non const int

    int j = 12;
    //* it makes the path const but the changes will be still reflected in k when changed in j
    const int &k = j;
    //! k++;
    j++;
    cout << j << endl;
    cout << k << endl;

    //? constant reference from a const int
    // * here both of the path are const and we can make changes either from them
    int const j2 = 12;
    int const &k2 = j2;
    //! j2++;
    //! k2++;

    //? reference from a const int
    //! we don't do that here

    int const j3 = 123;
    //! int &k3 = j3;

    return 0;
}