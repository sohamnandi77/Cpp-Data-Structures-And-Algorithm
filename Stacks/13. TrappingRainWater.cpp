#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int rainWater(vector<int> arr)
{
    stack<int> s;
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] < arr[i])
        {
            int curr = s.top();
            s.pop();
            if (s.empty())
                break;
            int diff = i - s.top() - 1;
            ans += (min(arr[s.top()], arr[i]) - arr[curr]) * diff;
        }
        s.push(i);
    }
    return ans;
}

int main()
{
    vector<int> arr = {3, 0, 1, 2, 5};
    cout << rainWater(arr) << endl;
    return 0;
}