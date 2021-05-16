#include <iostream>
using namespace std;

int main()
{
    // Advantages of this method is that we can make Jagged Arrays
    int m, n;
    cin >> m >> n;
    int **p = new int *[m]; // array of integer pointers

    // Create 2D array
    for (int i = 0; i < m; i++)
    {
        p[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }

    //* Printing 2D Array
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    //* deallocation of memory
    for (int i = 0; i < 10; i++)
    {
        delete[] p[i];
    }
    delete[] p;
    return 0;
}