#include <iostream>
#define ll long long
using namespace std;
//* OP Method
ll int sqRootFloor(ll int x)
{
    if (x == 0 || x == 1)
        return x;
    ll int low = 1;
    ll int high = x;
    ll int ans = 0;

    while (low <= high)
    {
        ll int mid = high + (low - high) / 2; //* important

        if (mid == x / mid)
            return mid;

        //! else if (mid*mid <= x) gives TLE(Time Limit Exceed)
        else if (mid <= x / mid) //* important
        {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int main()
{
    ll int n = 45654654;
    cout << sqRootFloor(n) << endl;
    return 0;
}