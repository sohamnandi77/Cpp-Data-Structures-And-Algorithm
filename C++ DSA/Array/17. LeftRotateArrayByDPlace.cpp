#include <iostream>
using namespace std;
void reverse(int arr[], int low, int high)
{
    while (low < high)
    {
        swap(arr[high], arr[low]);

        low++;
        high--;
    }
}

void leftRotate(int arr[], int d, int n)
{
    reverse(arr, 0, d - 1);

    reverse(arr, d, n - 1);

    reverse(arr, 0, n - 1);
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7}, n = 7, d = 3;

    cout << n / 3 << endl;
    cout << "Before Rotation" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    leftRotate(arr, d, n);

    cout << "After Rotation" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}