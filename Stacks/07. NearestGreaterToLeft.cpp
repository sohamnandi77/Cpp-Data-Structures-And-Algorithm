#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void nglNoob(int *arr, int n)
{

    cout << -1 << " ";
    for (int i = 1; i < n; i++)
    {
        bool flag = true;
        for (int j = i; j >= 0; j--)
            if (arr[j] > arr[i])
            {
                cout << arr[j] << " ";
                flag = false;
                break;
            }
        if (flag)
            cout << -1 << " ";
    }
}

vector<int> nglOP(int *arr, int n)
{
    stack<int> s;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
            res.push_back(-1);

        else if (!s.empty() && s.top() > arr[i])
            res.push_back(s.top());

        else if (!s.empty() && s.top() <= arr[i])
        {
            while (!s.empty() && s.top() <= arr[i])
                s.pop();
            if (s.empty())
                res.push_back(-1);
            else
                res.push_back(s.top());
        }

        s.push(arr[i]);
    }

    return res;
}

int main()
{
    int arr[] = {1, 9, 0, 0, 1, 2, 4, 8};
    int size = *(&arr + 1) - arr;
    nglNoob(arr, size);
    cout << endl;
    vector<int> res = nglOP(arr, size);
    for (auto x : res)
        cout << x << " ";

    return 0;
}