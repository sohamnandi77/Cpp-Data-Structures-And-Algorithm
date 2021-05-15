#include <iostream>
using namespace std;

const int R = 3, C = 3;

void Spiral(int arr[R][C])
{
    int top = 0, left = 0, bottom = R - 1, right = C - 1;
    while (top <= bottom && left <= right)
    {
        // top
        for (int i = left; i <= right; i++)
            cout << arr[top][i] << " ";
        top++;
        // right
        for (int i = top; i <= bottom; i++)
            cout << arr[i][right] << " ";
        right--;

        if (top <= bottom)
        {
            // bottom (reverse)
            for (int i = right; i >= left; i--)
                cout << arr[bottom][i] << " ";
            bottom--;
        }
        if (left <= right)
        {
            // left (reverse)
            for (int i = bottom; i >= top; i--)
                cout << arr[i][left] << " ";
            left++;
        }
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
    Spiral(arr);
    return 0;
}