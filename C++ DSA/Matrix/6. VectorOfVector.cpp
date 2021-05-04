#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m = 3, n = 2;
    vector<vector<int>> arr;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(10);
        }
        arr.push_back(v);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // * no of rows are also dynamic
    // ! not cache friendly
    return 0;
}