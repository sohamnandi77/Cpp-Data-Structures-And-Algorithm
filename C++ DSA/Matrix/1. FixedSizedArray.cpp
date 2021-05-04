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

    //* C++ y deafult stores array by row major order
    int a[3][2] = {10, 20, 30, 40, 50, 60};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}