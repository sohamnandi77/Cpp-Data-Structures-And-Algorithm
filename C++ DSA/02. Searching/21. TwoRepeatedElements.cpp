// ? You are given an array of N+2 integer elements. All elements of the array are in range 1 to N. Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.

#include <iostream>
#include <vector>
using namespace std;

vector<int> twoRepeated(int arr[], int N)
{
    // Your code here
    vector<int> p;
    int x = 0, y = 0, temp;
    for (int i = 0; i < N + 2; i++)
    {
        temp = abs(arr[i]);
        if (arr[temp] < 0)
        {
            if (x == 0)
                x = temp;
            else
                y = temp;
        }
        else
            arr[temp] = -arr[temp];
    }
    p.push_back(x);
    p.push_back(y);
    return p;
}

int main()
{
    int arr[] = {0, 1, 2, 7, 4, 6, 5, 7, 3}, n = 9;

    cout << "Space Solution" << endl;

    vector<int> res = twoRepeated(arr, n);
    for (int x : arr)
        cout << x << endl;
    return 0;
}