// ? Find Prime Number in Range

#include <iostream>
#include <vector>
using namespace std;

int PrimeInRange(int l, int r)
{
    int count = 0;
    vector<bool> arr((r - l + 1), true);

    // Special Cases
    arr[0] = false;
    arr[1] = false;
    arr[2] = true;
    for (int i = 4; i <= r; i += 2)
        arr[i] = false;

    for (int i = 3; i * i <= r; i += 2)
        if (arr[i])
            for (int j = i * i; j <= r; j += i)
                arr[j] = false;

    for (int i = l; i <= r; i++)
        if (arr[i])
            count++;
    return count;
}

int main()
{
    int l = 0, r = 10;
    cout << PrimeInRange(l, r) << endl;
    return 0;
}