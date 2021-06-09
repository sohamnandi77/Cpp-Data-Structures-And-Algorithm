#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

bool isOverlap(pair<int, int> a, pair<int, int> b)
{
    return b.first < a.second && b.first > a.first;
}

int maxSelect(pair<int, int> arr[], int n)
{
    sort(arr, arr + n, compare);
    int res = 1;
    pair<int, int> last_added = arr[0];
    for (int i = 1; i < n; i++)
        if (!isOverlap(last_added, arr[i]))
        {
            res += 1;
            last_added = arr[i];
        }

    return res;
}

int main()
{
    pair<int, int> arr[] = {make_pair(1, 3), make_pair(2, 4), make_pair(3, 8), make_pair(10, 11)};
    int n = *(&arr + 1) - arr;
    cout << maxSelect(arr, n) << endl;
    return 0;
}