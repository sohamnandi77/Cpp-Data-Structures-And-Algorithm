#include <iostream>
using namespace std;

void increment1(int **p) //! it won't work
{
    p += 1;
}
void increment2(int **p) //* it will work -> it will increment the address of our *p
{
    *p += 1;
}
void incremen3(int **p) //* it will work ->it will increment the value of our i
{
    **p += 1;
}

int main()
{
    int i = 10;
    int *p = &i;
    int **p2 = &p; //* Double Pointers -> they store the address of other Pointers

    cout << p2 << endl;
    cout << &p << endl;

    cout << p << endl;
    cout << *p2 << endl;
    cout << &i << endl;

    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;
    return 0;
}