#include <iostream>
using namespace std;

const int N = 3;

void Transpose(int arr[N][N])
{
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) // ? Traversing only the upper Diagonal
            swap(arr[i][j], arr[j][i]);
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
    cout << "Before Transpose" << endl;
    print(arr);

    Transpose(arr);

    cout << "After Transpose" << endl;
    print(arr);
    return 0;
}