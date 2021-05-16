#include <iostream>
using namespace std;
int main()
{
    int a[10]; //* it creates 40 byte (4*10 = 40)

    //? a is acting as a pointer pointing to 0th element of the array
    cout << a << endl;
    cout << &a << endl;
    cout << &a[0] << endl;

    a[0] = 5;
    a[1] = 10;

    //* a[i] ==> *(i+a)
    //? we can also use i[a] as it will be converted to *(i+a)
    cout << *a << endl;       // 5
    cout << *(a + 1) << endl; // 10
    cout << a[1] << endl;     // 10
    cout << 1 [a] << endl;    // 10

    int *p = &a[0];
    cout << a << endl;
    cout << p << endl;
    cout << sizeof(a) << endl; // 40
    cout << sizeof(p) << endl; // 4
    cout << *(p + 1) << endl;  // 10

    //! We can't do a++ or a = a+1;
    //* because array can not be reassigned

    // p = p + 1;
    // a != p
    // p = a
    return 0;
}