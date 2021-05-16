#include <iostream>
using namespace std;

//! Bad Practice -- Use Global Variables Carefully.
//! as anyone can change it any time
// ? Use pass by reference
int a;

void g()
{
    a++;
    cout << a << endl;
}
void f()
{
    cout << a << endl;
    a++;
    g();
}

int main()
{
    a = 10;
    f();
    return 0;
}