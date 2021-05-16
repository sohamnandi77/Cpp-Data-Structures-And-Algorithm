#include <iostream>
using namespace std;
void print(int *p)
{
    cout << *p << endl;
}

void IncrementPointer(int *p)
{
    ++p;
}

void Increment(int *p)
{
    (*p)++;
}

int main()
{
    int i = 10;
    int *p = &i;
    print(p);

    cout << p << endl;
    IncrementPointer(p); //* it will not change anything as it will first create a copy of the pointer and make changes to that copy
    cout << p << endl;

    cout << *p << endl;
    Increment(p); // * here we are make changes to the actual storage
    cout << *p << endl;
    return 0;
}