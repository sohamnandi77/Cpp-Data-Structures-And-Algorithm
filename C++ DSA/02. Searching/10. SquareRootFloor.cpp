#include <iostream>
#define ll long long
using namespace std;

int sqRootFloorNoob(int x)
{
    int i = 1;
    while (i <= x / i)
        i++;
    return i - 1;
}

ll int sqRootFloorOP(ll int x)
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
    cout << sqRootFloorNoob(n) << endl;
    cout << sqRootFloorOP(n) << endl;
    return 0;
}