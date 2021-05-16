#include <iostream>
#include <vector>
using namespace std;

const int R = 3, C = 3;

vector<vector<int>> sumMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    vector<vector<int>> ans;
    if (A.size() != B.size() || A[0].size() != B[0].size())
        return ans;

    for (int i = 0; i < A.size(); i++)
    {
        vector<int> v;
        for (int j = 0; j < A[i].size(); j++)
            v.push_back(A[i][j] + B[i][j]);
        ans.push_back(v);
    }
    return ans;
}

int main()
{
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> B = {{1, 3, 3}, {2, 3, 3}};
    vector<vector<int>> res = sumMatrix(A, B);
    for (auto i : res)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}