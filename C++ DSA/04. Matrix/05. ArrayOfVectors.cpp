#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m = 3, n = 2;
    vector<int> *arr = new vector<int>[m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i].push_back(10);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    delete[] arr;
    //! it is not cache friendly
    //* dynamic sized rows
    //* easy to pass to function
    return 0;
}