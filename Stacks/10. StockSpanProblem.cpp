#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void stockSpanNoob(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int span = 1;
        for (int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--)
            span++;
        cout << span << " ";
    }
}

vector<int> stockSpanOP(int *arr, int n)
{
    stack<pair<int, int>> s;
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (s.empty())
            res.push_back(i - (-1));

        else if (!s.empty() && s.top().first > arr[i])
            res.push_back(i - s.top().second);

        else if (!s.empty() && s.top().first <= arr[i])
        {
            while (!s.empty() && s.top().first <= arr[i])
                s.pop();
            if (s.empty())
                res.push_back(i - (-1));
            else
                res.push_back(i - s.top().second);
        }

        s.push(make_pair(arr[i], i));
    }

    return res;
}

int main()
{
    int arr[] = {100, 80, 60, 70, 60, 75, 85};
    int size = *(&arr + 1) - arr;
    stockSpanNoob(arr, size);
    cout << endl;
    vector<int> res = stockSpanOP(arr, size);
    for (auto x : res)
        cout << x << " ";

    return 0;
}