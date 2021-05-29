#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> multiplyMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int row = A.size();
    int col = A[0].size();
    if (!(row > 0))
        return vector<vector<int>>();
    if (!(col > 0))
        return vector<vector<int>>();
    if (!(col == B.size()))
        return vector<vector<int>>();
    int c1 = B[0].size();

    // * Resultant vector dimensions
    vector<vector<int>> ans(row, vector<int>(c1));
    for (int i = 0; i < row; i++)
        for (int j = 0; j < c1; j++)
            for (int k = 0; k < col; k++)
                ans[i][j] += A[i][k] * B[k][j];
    return ans;
}

int main()
{
    vector<vector<int>> A = {{4, 8},
                             {0, 2},
                             {1, 6}};
    vector<vector<int>> B = {{5, 2},
                             {9, 4}};

    vector<vector<int>> res = multiplyMatrix(A, B);
    for (auto x : res)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}