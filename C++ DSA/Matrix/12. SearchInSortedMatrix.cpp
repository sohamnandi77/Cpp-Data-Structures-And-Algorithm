#include <iostream>
using namespace std;

const int R = 3, C = 3;

void LinearSearch(int arr[R][C], int x)
{
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (arr[i][j] == x)
            {
                cout << "Found at: " << i << "," << j << endl;
                return;
            }
    cout << "Not Found" << endl;
}

void search(int arr[R][C], int x)
{
    int i = 0, j = C - 1;
    while (i < R && j >= 0)
    {
        if (arr[i][j] == x)
        {
            cout << "Found at: " << i << "," << j << endl;
            return;
        }
        else if (arr[i][j] > x)
            j--;
        else
            i++;
    }
    cout << "Not Found" << endl;
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
    LinearSearch(arr, 6);
    search(arr, 3);
    return 0;
}