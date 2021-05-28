#include <iostream>
#include <vector>
using namespace std;

vector<int> PrimeSieve(int n)
{
  vector<int> arr(n, 1);

  // Special Cases
  arr[0] = 0;
  arr[1] = 0;
  arr[2] = 1;

  for (int i = 4; i <= n; i += 2)
    arr[i] = 0;

  for (int i = 3; i * i <= n; i += 2)
    if (arr[i] == 1)
      for (int j = i * i; j <= n; j += i)
        arr[j] = 0;

  vector<int> primes;
  primes.reserve(n);
  primes.push_back(2);
  for (int i = 3; i <= arr.size(); i += 2)
    if (arr[i] == 1)
      primes.push_back(i);

  return primes;
}

vector<int> factorize(vector<int> &arr, int m)
{
  vector<int> factors;
  factors.reserve(m);

  int i = 0;
  int p = arr[0];
  while (p * p <= m)
  {
    if (m % p == 0)
    {
      factors.push_back(p);
      while (m % p == 0)
        m /= p;
    }
    i++;
    p = arr[i];
  }

  if (m != 1)
    factors.push_back(m);
  return factors;
}

int main()
{

  int n = 1000;
  vector<int> primes = PrimeSieve(n);
  int p = 456;
  vector<int> res = factorize(primes, p);
  for (auto x : res)
    cout << x << " ";
  return 0;
}