#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> intersectionNoob(int *a, int m, int *b, int n)
{
    vector<int> res;
    for (int i = 0; i < m; i++)
    {
        bool flag = false;
        for (int j = 0; j < i; j++)
        {
            if (a[i] == a[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == true)
            continue;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == b[j])
            {
                res.push_back(a[i]);
                break;
            }
        }
    }
    return res;
}

vector<int> intersectionOP(int *a, int m, int *b, int n)
{
    unordered_set<int> s(a, a + m);
    vector<int> res;
    for (int i = 0; i < n; i++)
    {
        if (s.find(b[i]) != s.end())
        {
            res.push_back(b[i]);
            s.erase(b[i]);
        }
    }
    return res;
}

int main()
{
    int arr1[] = {15, 17, 27, 27, 28, 15};
    int arr2[] = {16, 17, 28, 17, 31, 17};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    // vector<int> res = intersectionNoob(arr1, m, arr2, n);
    vector<int> res = intersectionOP(arr1, m, arr2, n);
    for (int x : res)
        cout << x << " ";
    return 0;
}