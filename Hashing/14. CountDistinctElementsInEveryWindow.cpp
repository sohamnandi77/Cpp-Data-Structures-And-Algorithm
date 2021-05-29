#include <iostream>
#include <unordered_map>
using namespace std;

void printDistinctNoob(int *arr, int n, int k)
{
    for (int i = 0; i <= n - k; i++)
    {
        int count = 0;
        for (int j = 0; j < k; j++)
        {
            bool flag = false;
            for (int l = 0; l < j; l++)
            {
                if (arr[i + j] == arr[i + l])
                {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
                count++;
        }
        cout << count << " ";
    }
}

void printDistinctOP(int *arr, int n, int k)
{
    unordered_map<int, int> m;
    for (int i = 0; i < k; i++)
        m[arr[i]] += 1;

    cout << m.size() << " ";
    for (int i = k; i < n; i++)
    {
        m[arr[i - k]] -= 1;
        if (m[arr[i - k]] == 0)
            m.erase(arr[i - k]);
        m[arr[i]] += 1;
        cout << m.size() << " ";
    }
}

int main()
{
    int arr[] = {10, 10, 5, 3, 20, 5};

    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    printDistinctNoob(arr, n, k);
    cout << endl;
    printDistinctOP(arr, n, k);
    return 0;
}