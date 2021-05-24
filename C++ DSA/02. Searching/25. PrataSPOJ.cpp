// ? Problem : https://www.spoj.com/problems/PRATA/

#include <iostream>
#define ll long long
#define mod 1000000007
using namespace std;

bool isFeasible(ll int *arr, ll int chef, ll int num, ll int mid)
{

    ll int time = 0;
    ll int prata = 0;
    for (ll int i = 0; i < chef; i++)
    {
        time = arr[i];
        ll int j = 2;
        while (time <= mid)
        {
            prata++;
            if (prata == num)
                return true;
            time += (j * arr[i]);
            j++;
        }
    }
    return false;
}

ll int noOfMinutes(ll int *arr, ll int chef, ll int num)
{
    ll int s = 0;
    // ll int e = (((num % mod) * ((num + 1) % mod)) % mod) / 2;
    ll int e = 10e8;
    ll int ans = 0;
    while (s <= e)
    {
        ll int mid = e + (s - e) / 2;
        if (isFeasible(arr, chef, num, mid))
        {
            e = mid - 1;
            ans = mid;
        }
        else
            s = mid + 1;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll int n, chef;
        cin >> n >> chef;
        ll int *arr = new ll int[chef];
        for (ll int i = 0; i < chef; i++)
            cin >> arr[i];
        cout << noOfMinutes(arr, chef, n) << endl;
        delete[] arr;
    }

    return 0;
}