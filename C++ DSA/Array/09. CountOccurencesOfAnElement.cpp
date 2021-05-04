#include <iostream>
using namespace std;
int CountOccurrences(int arr[], int n, int x)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == x)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 8, 9, 10};
    int size = *(&arr + 1) - arr;
    int x = 8;
    cout << CountOccurrences(arr, size, x) << endl;

    return 0;
}