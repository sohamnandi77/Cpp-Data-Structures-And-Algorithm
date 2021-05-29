#include <iostream>
#include <vector>
using namespace std;

void minStrength(vector<vector<char>> arr, int k, int s)
{
    int n = arr.size();    // * Row Size
    int m = arr[0].size(); // * Column Size
    int min_count = s;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (min_count < k)
            {
                cout << "No" << endl;
                return;
            }

            if (arr[i][j] == '.')
                min_count -= 2;
            else if (arr[i][j] == '*')
                min_count += 5;
            else
                break;
            if (j != n - 1)
                min_count--;
        }
    }
    cout << "yes " << min_count << endl;
}

int main()
{
    int k = 13, s = 20;
    vector<vector<char>> arr = {{'.', '.', '*', '.'},
                                {'.', '#', '.', '.'},
                                {'*', '*', '.', '.'},
                                {'.', '#', '*', '*'}};
    minStrength(arr, k, s);
    return 0;
}