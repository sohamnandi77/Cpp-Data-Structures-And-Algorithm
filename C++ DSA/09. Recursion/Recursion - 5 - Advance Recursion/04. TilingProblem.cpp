#include <iostream>
using namespace std;

int countTiles(int x, int y) // forms a n bonacci series
{
    if (y == 0 || y == 1)
        return y;

    return countTiles(x, y - 1) + countTiles(x, y - x);
}

int main()
{
    int board_x = 2;
    int board_y = 10;

    // tile size will always be (board_x * 1)

    cout << countTiles(board_x, board_y) << endl;

    return 0;
}