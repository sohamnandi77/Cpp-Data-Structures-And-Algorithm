#include <iostream>
#include <vector>
using namespace std;

const int R = 3, C = 2;

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
    int arr[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int rows = sizeof(arr) / sizeof(arr[0]); // returns rows
    int cols = sizeof(arr[0]) / sizeof(int); // returns col
    print(arr);
    return 0;
}