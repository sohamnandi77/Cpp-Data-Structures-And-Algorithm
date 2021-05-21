#include <iostream>
#include <vector>
using namespace std;

int sumSubmatrixNoob(vector<vector<int>> &arr)
// # Time Complexity: O(n^6)
{
    int n = arr.size();
    int m = arr[0].size();
    int sum = 0;
    for (int li = 0; li <= n - 1; li++)
        for (int lj = 0; lj <= m - 1; lj++)
            for (int bi = li; bi <= n - 1; bi++)
                for (int bj = lj; bj <= m - 1; bj++)
                    for (int i = li; i <= bi; i++)
                        for (int j = lj; j <= bj; j++)
                            sum += arr[i][j];
    return sum;
}

int sumSubmatrixBetter(vector<vector<int>> &arr)
{
    int n = arr.size();    // row
    int m = arr[0].size(); //col
    int sum = 0;
    // * Prefix Matrix
    vector<vector<int>> psa(arr);
    // Do column wise sum
    for (int i = 1; i <= m - 1; i++)
        for (int j = 0; j <= n - 1; j++)
            psa[j][i] += psa[j][i - 1];

    // Do row wise sum
    for (int i = 1; i <= n - 1; i++)
        for (int j = 0; j <= m - 1; j++)
            psa[i][j] += psa[i - 1][j];

    // Displaying the 2D vector
    // for (int i = 0; i < psa.size(); i++)
    // {
    //     for (int j = 0; j < psa[i].size(); j++)
    //         cout << psa[i][j] << " ";
    //     cout << endl;
    // }

    for (int li = 0; li <= n - 1; li++)
        for (int lj = 0; lj <= m - 1; lj++)
            for (int bi = li; bi <= n - 1; bi++)
                for (int bj = lj; bj <= m - 1; bj++)
                {
                    sum += psa[bi][bj];
                    if (li > 0)
                        sum = sum - (psa[li - 1][bj]);
                    if (lj > 0)
                        sum = sum - (psa[bi][lj - 1]);
                    if (li > 0 && lj > 0)
                        sum = sum + (psa[li - 1][lj - 1]);
                }

    return sum;
}
int sumSubmatrixOP(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            // Number of ways to choose from top-left elements
            int tl = (i + 1) * (j + 1);
            // Number of ways to choose from bottom-right elements
            int br = (n - i) * (m - j);
            sum += (tl * br) * arr[i][j];
        }
    return sum;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4, 6},
                               {5, 3, 8, 1, 2},
                               {4, 6, 7, 5, 5},
                               {2, 4, 8, 9, 4}};
    cout << sumSubmatrixNoob(arr) << endl;
    cout << sumSubmatrixBetter(arr) << endl;
    cout << sumSubmatrixOP(arr) << endl;
    return 0;
}