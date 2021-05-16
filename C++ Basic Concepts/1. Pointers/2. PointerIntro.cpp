#include <iostream>
using namespace std;
int main()
{
    int i;
    cout << i << endl;
    i++;
    cout << i << endl;

    // ! It won't give an error, But Never Do this
    // int *p;
    // cout << p << endl;
    // cout << *p << endl;

    //* Always allocate when initialize a pointer

    int *p = 0;         //? NULL pointer
    cout << p << endl;  // 0
    cout << *p << endl; //! Segmentation Fault

    //! incrementing NULL pointer will surely give an error: Segmentation Fault
    (*p)++;
    cout << *p << endl;
}