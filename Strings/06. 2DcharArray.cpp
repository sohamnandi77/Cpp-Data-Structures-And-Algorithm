#include <iostream>
using namespace std;

int main()
{
    char a[2][5] = {{'a', 'b', 'c', 'd', 's'}, {'e', 'f', 'g', 'h', 'q'}};
    cout << a[0][0] << endl;
    cout << a[0] << endl;
    cout << a[1] << endl;

    // -> Here the size is more than the column values so extra elements will be simply zero and cout will print the actual data
    char a1[2][6] = {{'a', 'b', 'c', 'd', 's'}, {'e', 'f', 'g', 'h', 'q'}};
    cout << a1[0][0] << endl;
    cout << a1[0] << endl;
    cout << a1[1] << endl;

    // * Another way to create a list of Strings is
    // # here they are by default NULL terminated
    char words[10][100] = {"Apple", "Mango", "Banana"};

    cout << words[0] << endl;

    return 0;
}