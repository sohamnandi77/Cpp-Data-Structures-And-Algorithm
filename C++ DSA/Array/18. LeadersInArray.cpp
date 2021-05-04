#include <iostream>
using namespace std;
// Noob Method
void leadersNoob(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = false;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] <= arr[j])
            {
                flag = true;
                break;
            }
        }

        if (flag == false)
        {
            cout << arr[i] << " ";
        }
    }
}

// OP Method
void leadersOP(int arr[], int n)
{
    int curr_leader = arr[n - 1];
    cout << arr[n - 1] << " ";
    for (int i = n - 2; i >= 0; i--)
    {
        if (curr_leader < arr[i])
        {
            curr_leader = arr[i];
            cout << arr[i] << " ";
        }
    }
}

int main()
{
    int arr[] = {7, 10, 4, 10, 6, 5, 2}, n = 7;
    cout << "Noob Approach" << endl;
    leadersNoob(arr, n);
    cout << endl;
    cout << "OP Approach" << endl;
    leadersOP(arr, n);
    cout << endl;
    return 0;
}