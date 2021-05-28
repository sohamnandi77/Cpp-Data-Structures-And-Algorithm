#include <iostream>
#include <vector>
using namespace std;

bool checkPrime(int n)
{
    for (int i = 2; i <= n / i; i++)
        if (n % i == 0)
            return false;
    return true;
}

int countPrimeNoob(int n)
// * Time Complexity: O(n^3/2)
{
    int count = 0;
    for (int i = 2; i <= n; i++)
        if (checkPrime(i))
            count++;
    return count;
}

// * Sieve Of Erathosthenes
// # Time Complexity: O(nlog(logn))
// * Space Complexity: O(n)
int countPrimeOP(int n)
{
    int count = 0;
    vector<bool> arr((n + 1), true);

    // Special Cases
    arr[0] = false;
    arr[1] = false;
    arr[2] = true;

    for (int i = 3; i * i <= n; i += 2)
        if (arr[i] == true)
            for (int j = i * i; j <= n; j += i)
                arr[j] = false;
    for (int i = 0; i <= n; i++)
        // cout << i << " : " << arr[i] << endl;
        if (arr[i])
            count++;
    return count;
}

int main()
{
    int n = 100;
    cout << countPrimeNoob(n) << endl;
    cout << countPrimeOP(n) << endl;
    return 0;
}