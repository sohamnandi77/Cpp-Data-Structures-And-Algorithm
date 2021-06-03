#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void printNByKNoob(int arr[], int n, int k)
// * Time Complexity: O(nlogn)
{
    sort(arr, arr + n);
    int min_times = n / k;
    int i = 1, count = 1;
    while (i < n)
    {
        while (i < n && arr[i] == arr[i - 1])
        {
            count++;
            i++;
        }
        if (count > min_times)
            cout << arr[i - 1] << " ";
        count = 1;
        i++;
    }
}

void printNByKBetter(int arr[], int n, int k)
// * Time Complexity: O(n)
// * Space Complexity: O(n)
{
    int min_times = n / k;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
    for (auto e : m)
        if (e.second > min_times)
            cout << e.first << " ";
}

void printNByKOP(int arr[], int n, int k)
// * Time Complexity: O(nk)
// * Space Complexity: O(k)
{
    int min_times = n / k;
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) != m.end())
            m[arr[i]]++;
        else if (m.size() < k - 1)
            m[arr[i]] = 1;
        else
            for (auto x : m)
            {
                x.second--;
                if (x.second == 0)
                    m.erase(x.first);
            }
    }
    for (auto x : m)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (x.first == arr[i])
                count++;
        }
        if (count > min_times)
            cout << x.first << " ";
    }
}

int main()
{
    int arr[] = {10, 10, 20, 30, 20, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    printNByKNoob(arr, n, k);
    cout << endl;
    printNByKBetter(arr, n, k);
    cout << endl;
    printNByKOP(arr, n, k);
    return 0;
}