#include <iostream>
using namespace std;

//* Pass by Reference
void increment(int &n)
{
    n++;
}

//! Bad Practice - beware before doing that
//? reference to local variable 'a' is returned
// scope of a is only within this function
int &f(int n)
{
    int a = n;
    return a;
}

//* replacement
int &f1(int n, int a = 0)
{
    a = n;
    return a;
}

//! Bad Practice - beware before doing that
//? address of local variable 'i' is returned
int *f2(int n)
{
    int i = 10;
    return &i;
}

int main()
{
    int i = 10;
    increment(i);
    cout << i << endl;

    int &k = f(i); //! we are trying to access a reference of local variable

    int *p = f2(i); //! same with pointers -> we are trying to access address of local variable

    return 0;
}