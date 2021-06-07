#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> nsl(vector<int> &arr, int n)
{
    stack<pair<int, int>> s;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
            res.push_back(i - (-1) - 1);

        else if (!s.empty() && s.top().first < arr[i])
            res.push_back(i - s.top().second - 1);

        else if (!s.empty() && s.top().first >= arr[i])
        {
            while (!s.empty() && s.top().first >= arr[i])
                s.pop();
            if (s.empty())
                res.push_back(i - (-1) - 1);
            else
                res.push_back(i - s.top().second - 1);
        }

        s.push(make_pair(arr[i], i));
    }

    return res;
}

vector<int> nsr(vector<int> &arr, int n)
{
    stack<pair<int, int>> s;
    vector<int> res;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
            res.push_back(1);

        else if (!s.empty() && s.top().first < arr[i])
            res.push_back(s.top().second - i);

        else if (!s.empty() && s.top().first >= arr[i])
        {
            while (!s.empty() && s.top().first >= arr[i])
                s.pop();
            if (s.empty())
                res.push_back(1);
            else
                res.push_back(s.top().second - i);
        }

        s.push(make_pair(arr[i], i));
    }
    reverse(res.begin(), res.end());
    return res;
}

int maxAreaHist(vector<int> &arr, int n)
{
    vector<int> res_nsl = nsl(arr, n); // * returns smaller element to the left - 1
    vector<int> res_nsr = nsr(arr, n); // * returns smaller element to the right

    int mx = -1;
    for (auto i = 0; i < n; i++)
        mx = max(mx, (res_nsr[i] + res_nsl[i]) * arr[i]);

    return mx;
}

int maxAreaBinary(vector<vector<int>> arr, int row, int col)
{
    int res = INT_MIN;
    vector<int> h(col, 0);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == 0)
                h[j] = 0;
            else
                h[j] += arr[i][j];
        }

        // * prnting the individual histograms (or arrays)
        for (auto x : h)
            cout << x << " ";

        int area = maxAreaHist(h, col);
        cout << "Area: " << area << endl;
        res = max(res, area);
    }
    return res;
}

int main()
{
    vector<vector<int>> arr = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    int row = arr.size();
    int col = arr[0].size();
    cout << maxAreaBinary(arr, row, col) << endl;
    return 0;
}