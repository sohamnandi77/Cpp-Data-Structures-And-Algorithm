// ? Check if array is sorted or not

#include <iostream>
using namespace std;
bool checkSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }
    return true;
}
int main()
{
    int arr[] = {5, 20, 12, 20, 8};
    cout << checkSorted(arr, 5) << endl;
    return 0;
}