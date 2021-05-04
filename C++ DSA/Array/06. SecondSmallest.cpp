#include <iostream>
using namespace std;
int secondSmallest(int arr[], int n)
{
    int res = INT_MIN, smallest = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[smallest])
        {
            res = smallest;
            smallest = i;
        }
        else if (arr[i] != arr[smallest])
        {
            if (res == -1 || arr[i] < arr[res])
                res = i;
        }
    }
    return res;
}

int main()
{
    int arr[] = {5, 20, 8, 20, 10};
    cout << secondSmallest(arr, 5) << endl;
    return 0;
}