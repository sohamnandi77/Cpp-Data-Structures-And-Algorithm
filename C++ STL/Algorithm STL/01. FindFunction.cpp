#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 4, 4, 4};
    int n = *(&arr + 1) - arr;

    int key = 4;

    auto it = find(arr, arr + n, key);
    int index = it - arr;
    cout << index << endl;

    
    return 0;
}