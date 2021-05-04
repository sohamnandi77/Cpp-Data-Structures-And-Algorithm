#include <iostream>
using namespace std;
int subsetSum(int a[], int size, int sum)
{
    if (size == 0)
    {
        return (sum == 0) ? 1 : 0;
    }
    return subsetSum(a, size - 1, sum) + subsetSum(a, size - 1, sum - a[size - 1]);
}
int main()
{
    int a[3] = {10, 20, 15};
    int sum = 25;
    int size = sizeof(a) / sizeof(a[0]);
    cout << subsetSum(a, size, sum) << endl;
    return 0;
}