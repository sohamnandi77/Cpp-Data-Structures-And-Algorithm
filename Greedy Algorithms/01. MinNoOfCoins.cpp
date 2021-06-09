#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// ! Greedy implementation might not always work. So, this might not be a optimal solution.
int minNumOfCoins(int *arr, int n, int amount)
{
    sort(arr, arr + n);
    int res = 0;
    for (int i = n - 1; i >= 0; i++)
    {
        if (arr[i] <= amount)
        {
            int c = floor(amount / arr[i]);
            res += c;
            amount -= (c * arr[i]);
        }
        if (amount == 0)
            break;
    }

    if (amount != 0)
        return -1;

    return res;
}

int main()
{
    int coin[] = {5, 10, 2, 1};
    int n = *(&coin + 1) - coin;
    int amount = 57;
    cout << minNumOfCoins(coin, n, amount) << endl;
    return 0;
}