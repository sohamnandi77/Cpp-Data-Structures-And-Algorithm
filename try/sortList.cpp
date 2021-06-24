#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

void sortList(vector<pair<string, int>> &arr)
{
    sort(arr.begin(), arr.end(), compare);
}

int main()
{
    int min_salary, n = 3;

    vector<pair<string, int>> arr = {make_pair("ide", 10), make_pair("gfg", 250), make_pair("aqewew", 10)};

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i].first << " " << arr[i].second << endl;
    sortList(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i].first << " " << arr[i].second << endl;
    return 0;
}