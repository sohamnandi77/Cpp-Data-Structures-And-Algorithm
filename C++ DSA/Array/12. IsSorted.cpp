#include <iostream>
using namespace std;
int isSorted(int arr[], int n)
{

    int increase_sorted = 1;
    int decrease_sorted = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            increase_sorted = 0;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i + 1] > arr[i])
        {
            decrease_sorted = 0;
            break;
        }
    }

    return increase_sorted || decrease_sorted;
}

int main()
{

    int arr[4] = {4, 4, 4, 5};
    int N = 4;
    cout << isSorted(arr, N);
    cout << endl;

    return 0;
}