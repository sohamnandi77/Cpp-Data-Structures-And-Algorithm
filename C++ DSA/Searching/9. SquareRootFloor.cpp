#include <iostream>
using namespace std;
//* OP Method
long long int sqRootFloor(long long int x)
{
    if (x == 0 || x == 1)
        return x;
    long long int low = 1;
    long long int high = x;
    long long int ans = 0;

    while (low <= high)
    {
        long long int mid = high + (low - high) / 2; //* important

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
    long long int n = ;
    cout << sqRootFloor(n) << endl;
    return 0;
}