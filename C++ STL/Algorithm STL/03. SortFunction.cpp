#include <iostream>
#include <algorithm>
using namespace std;

// Define a Comparator Function
bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int arr[] = {12, 65, 85, 21, 36, 91, 42, 75, 2, 21};
    int n = *(&arr + 1) - arr;
    for (int x : arr)
        cout << x << " ";

    cout << endl;
    sort(arr, arr + n, compare);

    for (int x : arr)
        cout << x << " ";
    return 0;
}