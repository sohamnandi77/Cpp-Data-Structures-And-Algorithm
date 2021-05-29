// ? Given a square matrix of size N *N, print the sum of upper and lower triangular elements.Upper Triangle consists of elements on the diagonal and above it.The lower triangle consists of elements on the diagonal and below it.

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumTriangles(const vector<vector<int>> &a, int n)
{
    int lowerSum = 0, upperSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //diagonal elements will be common in both upper and lower sum.
            if (i == j)
            {
                upperSum += a[i][j];
                lowerSum += a[i][j];
            }
            else if (i < j)
                upperSum += a[i][j];
            else
                lowerSum += a[i][j];
        }
    }

    vector<int> res = {upperSum, lowerSum};
    return res;
}

int main()
{
    vector<vector<int>> arr = {{6, 5, 4},
                               {1, 2, 5},
                               {7, 9, 7}};
    int n = arr.size();
    vector<int> res = sumTriangles(arr, n);
    for (int x : res)
        cout << x << " ";
    return 0;
}