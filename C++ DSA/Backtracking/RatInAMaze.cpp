// {1,0,1,0,1}
// {1,1,1,1,1}
// {0,1,0,1,0}
// {1,0,0,1,1}
// {1,1,1,0,1}

// {1,0,0,0,0}
// {1,1,1,1,0}
// {0,0,0,1,0}
// {0,0,0,1,1}
// {0,0,0,0,1}

#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    if (x < n && y < n && arr[x][y] == 1)
        return true;
    return false;
}

bool ratInAMaze(int **arr, int x, int y, int n, int **solArr)
{
    if (x == n - 1 && y == n - 1)
    {
        solArr[x][y] = 1;
        return true;
    }
    if (isSafe(arr, x, y, n))
    {
        solArr[x][y] = 1;
        if (ratInAMaze(arr, x + 1, y, n, solArr))
            return true;

        if (ratInAMaze(arr, x, y + 1, n, solArr))
            return true;

        solArr[x][y] = 0; //backtracking
        return false;
    }
}

int main()
{

    int n;
    cin >> n;
    return 0;
}