#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 4, 4, 4};
    int n = *(&arr + 1) - arr;

    int key = 4;

    bool present = binary_search(arr, arr + n, key);
    cout << present << endl;

    // * Get the index of the element
    // lower_bound(s,e,key) and upper_bound(s,e,key)

    auto lb = lower_bound(arr, arr + n, key); // returns the first index of the element >= key
    int index = lb - arr;
    cout << index << endl;

    auto ub = upper_bound(arr, arr + n, key); // returns the next element after the last index of the element < key
    index = ub - arr;
    cout << index << endl;

    // Frequency of the element in the array
    cout << ub - lb << endl;
    return 0;
}