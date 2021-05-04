#include <iostream>
using namespace std;

// void g(int const &a)
// {
//     (*a)++;
// }

// void f1(int const *p)
// {
//     (*p)++;
// }

void f(int *p)
{
    (*p)++;
}

int main()
{
    // ? pointer to a const int [Not Allowed]
    int const i = 10;
    //! int *p = &i;

    // ? const pointer to a const int [Allowed but can't make changes]
    int const h = 10;
    int const *p = &h;
    //! (*p)++;

    // ? const pointer to a non-const int [Allowed but can't make changes]
    int j = 12;
    int const *p2 = &j;
    cout << *p2 << endl;
    //! (*p2)++;
    j++;
    cout << *p2 << endl;

    int k = 12;
    int *p3 = &k;

    // These function now will won't able to change the value
    //! f1(p3);
    //! g(j);

    int x = 10;
    int y = 21;

    //* Here we are saying we can't change the path where p is pointing; but p can change itself

    int const *ptr = &x;
    //! (*ptr)++;  Not allowed
    ptr = &y; //we can change p

    //* Here we are saying we can't change the p
    int *const ptr2 = &x;
    //! so we can't do this
    //! ptr2 = &y;
    (*ptr2)++; // we can change where p is pointing

    //* Here we are saying we can't change the path where p is pointing and p as well
    int const *const ptr3 = &i;

    //! so we can't do this
    //! ptr3 =&j;
    //! (*ptr3)++;

    return 0;
}