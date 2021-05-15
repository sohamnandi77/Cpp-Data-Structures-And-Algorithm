// * Elements are stored in row-major order in C++
#include <iostream>
using namespace std;

int main()
{
    int arr[3][2] = {
        {10, 20},
        {30, 40},
        {50, 60}};

    // * row loop
    for (int i = 0; i < 3; i++)
    {
        //* column loop
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //* C++ y default stores array by row major order
    int a[3][2] = {10, 20, 30, 40, 50, 60}; // # internal Brackets are optional
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // * Only the first Dimension can be Omitted when we initialize
    int a2[][2] = {{1, 2}, {3, 4}, {5, 6}};

    int a3[][2][2] = {{{1, 2}, {3, 4}},
                      {{5, 6}, {7, 8}}};

    return 0;
}