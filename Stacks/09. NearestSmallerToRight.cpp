#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void nsrNoob(int *arr, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[i])
            {
                cout << arr[j] << " ";
                flag = false;
                break;
            }
        if (flag)
            cout << -1 << " ";
    }
    cout << -1 << " ";
}

vector<int> nsrOP(int *arr, int n)
{
    stack<int> s;
    vector<int> res;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
            res.push_back(-1);

        else if (!s.empty() && s.top() < arr[i])
            res.push_back(s.top());

        else if (!s.empty() && s.top() >= arr[i])
        {
            while (!s.empty() && s.top() >= arr[i])
                s.pop();
            if (s.empty())
                res.push_back(-1);
            else
                res.push_back(s.top());
        }

        s.push(arr[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int arr[] = {1, 9, 0, 0, 1, 12, 3, 8};
    int size = *(&arr + 1) - arr;
    nsrNoob(arr, size);
    cout << endl;
    vector<int> res = nsrOP(arr, size);
    for (auto x : res)
        cout << x << " ";

    return 0;
}