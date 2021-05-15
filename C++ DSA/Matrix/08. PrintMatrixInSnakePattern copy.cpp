#include <iostream>
using namespace std;

const int R = 3, C = 3;

void printSnake(int mat[R][C])
{
    for (int i = 0; i < R; i++)
    {
        if (i % 2 == 0)
            for (int j = 0; j < C; j++)
                cout << mat[i][j] << " ";
        else
            for (int j = C - 1; j >= 0; j--)
                cout << mat[i][j] << " ";
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
    printSnake(arr);
    return 0;
}