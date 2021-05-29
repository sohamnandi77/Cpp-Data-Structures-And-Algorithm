#include <iostream>
using namespace std;

int isFeasible(int n, int m, int x, int y, int mid)
{
    if ((mid * x) <= m + (n - mid) * y)
        return true;
    else
        return false;
}

int maxStudents(int n, int m, int x, int y)
{
    int s = 0;
    int e = 100000000;
    int ans;
    while (s <= e)
    {
        int mid = e + (s - e) / 2;
        if (isFeasible(n, m, x, y, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return ans;
}

int main()
{
    int n = 5, m = 10, x = 2, y = 1;
    cout << maxStudents(n, m, x, y) << endl;
    return 0;
}