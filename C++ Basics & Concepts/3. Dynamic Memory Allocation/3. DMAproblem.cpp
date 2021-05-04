#include <iostream>
using namespace std;

int *fun()
{
    //? Never return local variable
    //! int a[5] = {1, 2, 3, 4, 5};
    int *a = new int[5]{1, 2, 3, 4, 5};
    cout << "value of a: " << a << endl;
    cout << "value of a[0]: " << a[0] << endl;
    return a;
}

int main()
{
    int *b = fun();
    cout << "value of b: " << b << endl;
    cout << "value of b[0]: " << b[0] << endl;
    delete[] b;
    return 0;
}