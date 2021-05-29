#include <iostream>
#include <algorithm>
using namespace std;

const int R = 3, C = 3;

void LinearSearch(int arr[R][C], int x)
// # Time Complexity: O(n^2)
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

void RowBinarySearch(int arr[R][C], int x)
// # Time Complexity: O(nlogn)
{
    for (int i = 0; i < C; i++)
    {
        int low = 0;
        int high = R - 1;
        while (low <= high)
        {
            int mid = high + (low - high) / 2;

            if (arr[i][mid] == x)
            {
                cout << "Found at: " << i << "," << mid << endl;
                return;
            }

            else if (arr[i][mid] > x)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    cout << "Not Found" << endl;
}

void StaircaseSearch(int arr[R][C], int x)
// # Time Complexity: O(n)
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
    RowBinarySearch(arr, 6);
    StaircaseSearch(arr, 6);
    return 0;
}