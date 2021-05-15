#include <iostream>
using namespace std;

const int N = 3;

void AntiRotate90Noob(int arr[N][N])
{
    int temp[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[N - j - 1][i] = arr[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            arr[i][j] = temp[i][j];
}

void Transpose(int arr[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) // ? Traversing only the upper Diagonal
            swap(arr[i][j], arr[j][i]);
}

void AntiRotate90(int arr[N][N])
{
    Transpose(arr);

    // * Reverse Rows
    for (int i = 0; i < N; i++)
    {
        int low = 0, high = N - 1;
        while (low < high)
            swap(arr[low++][i], arr[high--][i]);
    }
}

void print(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Before Rotation" << endl;
    print(arr);

    // AntiRotate90Noob(arr);
    AntiRotate90(arr);

    cout << "After Rotation" << endl;
    print(arr);
    return 0;
}