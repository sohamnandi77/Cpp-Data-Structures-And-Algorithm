#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> nsl(int *arr, int n)
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

vector<int> nsr(int *arr, int n)
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

int maxAreaHist(int *arr, int n)
{
    vector<int> res_nsl = nsl(arr, n); // * returns smaller element to the left - 1
    vector<int> res_nsr = nsr(arr, n); // * returns smaller element to the right

    int mx = -1;
    for (auto i = 0; i < n; i++)
        mx = max(mx, (res_nsr[i] + res_nsl[i]) * arr[i]);

    return mx;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};
    int size = *(&arr + 1) - arr;
    cout << maxAreaHist(arr, size) << endl;
    return 0;
}