#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int &j = i;

    //! int &j; reference variable must be initialized when allocated

    i++;
    cout << i << endl;
    cout << j << endl; //? changes will be reflected in both

    int k = 100;
    j = k;
    cout << k << endl;
    return 0;
}