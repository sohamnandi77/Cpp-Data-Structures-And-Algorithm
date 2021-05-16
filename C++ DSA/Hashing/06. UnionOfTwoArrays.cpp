#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<int> UnionOP(int *a, int m, int *b, int n)
{
    unordered_set<int> s(a, a + m);
    vector<int> res;
    for (int i = 0; i < n; i++)
        s.insert(b[i]);
    for (int x : s)
        res.push_back(x);
    return res;
}

int main()
{
    int arr1[] = {15, 17, 27, 27, 28, 15};
    int arr2[] = {16, 17, 28, 17, 31, 17};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    vector<int> res = UnionOP(arr1, m, arr2, n);
    for (int x : res)
        cout << x << " ";
    return 0;
}