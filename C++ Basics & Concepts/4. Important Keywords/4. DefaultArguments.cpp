#include <iostream>
using namespace std;
int sum(int a[], int size, int si = 0)
{
    int ans = 0;
    for (int i = si; i < size; i++)
    {
        ans += a[i];
    }
    return ans;
}

int sum2(int a = 0, int b = 0, int c = 0, int d = 0)
{
    return a + b + c + d;
}

int main()
{
    int a[20];
    cout << sum(a, 20) << endl;
    return 0;
}