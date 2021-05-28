#include <iostream>
using namespace std;
int len(char *str)
{
    if (str[0] == '\0')
        return 0;

    return len(str + 1) + 1;
}
int main()
{
    char str[100] = "Hello";
    cout << len(str) << endl;
    return 0;
}