#include <iostream>
using namespace std;
int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5};
    int x = 4;
    cout << linearSearch(arr, 6, 4) << endl;

    return 0;
}