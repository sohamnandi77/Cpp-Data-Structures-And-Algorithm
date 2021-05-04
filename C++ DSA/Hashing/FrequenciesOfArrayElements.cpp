#include <iostream>
#include <unordered_map>
using namespace std;

void countFreqNoob(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        // check if seen before
        for (int j = 0; j < i; j++)
        {
            if (arr[j] == arr[i])
            {
                flag = true;
                break;
            }
        }
        // if seen ignore;
        if (flag == true)
            continue;

        // if not seen before count frequency
        int freq = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                freq++;
            }
        }
        cout << arr[i] << " " << freq << endl;
    }
}

void countFreqOP(int *arr, int n)
{
    unordered_map<int, int> h;
    for (int i = 0; i < n; i++)
        h[arr[i]]++;
    for (auto e : h)
    {
        cout << e.first << " " << e.second << endl;
    }
}

int main()
{
    int arr[] = {10, 20, 10, 30, 50, 30, 20};
    int size = *(&arr + 1) - arr;
    countFreqNoob(arr, size);
    countFreqOP(arr, size);
    return 0;
}