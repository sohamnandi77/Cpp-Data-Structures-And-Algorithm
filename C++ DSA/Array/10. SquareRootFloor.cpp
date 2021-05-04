#include <iostream>
using namespace std;
// Noob Method
//* See Searching for a OP Method
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