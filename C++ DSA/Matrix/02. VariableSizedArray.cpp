// from C14 variable sized arrays are allowed

#include <iostream>
using namespace std;

int main()
{
    int m = 3, n = 2;
    int arr[m][n]; //! but it's not preferred
    // * row loop
    for (int i = 0; i < m; i++)
    {
        //* column loop
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = i + j;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}