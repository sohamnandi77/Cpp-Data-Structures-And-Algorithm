#include <iostream>
using namespace std;

const int R = 3, C = 3;

void BoundaryTraversal(int arr[R][C])
{
    if (R == 1)
        for (int i = 0; i < C; i++)
            cout << arr[0][i] << " ";
    if (C == 1)
        for (int i = 0; i < R; i++)
            cout << arr[i][0] << " ";
    else
    {
        for (int i = 0; i < C; i++)
            cout << arr[0][i] << " ";
        for (int i = 1; i < R; i++)
            cout << arr[i][C - 1] << " ";
        for (int i = C - 2; i >= 0; i--)
            cout << arr[R - 1][i] << " ";
        for (int i = R - 2; i >= 1; i--)
            cout << arr[i][0] << " ";
    }
}

void print(int arr[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print(arr);
    BoundaryTraversal(arr);
    return 0;
}