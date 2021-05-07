// ? Find the Floor of Square root of a Number
//* See Searching for a OP Method

#include <iostream>
using namespace std;
// Noob Method
int sqRootFloor(int x)
{
    int i = 1;
    while (i * i <= x)
    {
        i++;
    }
    return i - 1;
}
int main()
{
    int n = 25;
    cout << sqRootFloor(25) << endl;
    return 0;
}