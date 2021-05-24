#include <iostream>
#define ll long long
using namespace std;
//* OP Method
float sqRootFloor(ll int x, int p)
{
    if (x == 0 || x == 1)
        return x;
    ll int low = 1;
    ll int high = x;
    float ans = 0;

    while (low <= high)
    {
        ll int mid = high + (low - high) / 2; //* important

        if (mid == x / mid)
        {
            ans = mid;
            break;
        }

        //! else if (mid*mid <= x) gives TLE(Time Limit Exceed)
        else if (mid <= x / mid) //* important
        {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }

    // Factional Part
    float inc = 0.1;
    for (int i = 0; i < p; i++)
    {
        while (ans <= x / ans)
            ans += inc;
        ans -= inc;
        inc = inc / 10;
    }
    return ans;
}
int main()
{
    ll int n = 45654654;
    int p = 3;
    cout << sqRootFloor(n, p) << endl;
    return 0;
}