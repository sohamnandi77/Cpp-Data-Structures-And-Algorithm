// ? First Index of a Number
// * Also check the recursive Method in Recursion

#include <iostream>
#define ll long long
using namespace std;
ll FirstIndex(ll arr[], ll n, ll x)
{
  for (ll i = 0; i < n - 1; i++)
  {
    if (arr[i] == x)
    {
      return i;
    }
  }
  return -1;
}
int main()
{
  ll arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  ll size = *(&arr + 1) - arr;
  ll x = 5;
  cout << FirstIndex(arr, size, x) << endl;
  return 0;
}