#include <iostream>
using namespace std;

int main()
{
    int m = 3, n = 2;
    int **arr;
    arr = new int *[m];
    for (int i = 0; i < m; i++)
        arr[i] = new int[n];
    // * row loop
    for (int i = 0; i < m; i++)
    {
        //* column loop
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 10;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    //* we can make jagged array using this method.
    //* We can pass it to a function
    // ! it's not cache friendly

    return 0;
}