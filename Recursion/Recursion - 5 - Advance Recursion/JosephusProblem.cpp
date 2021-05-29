#include <iostream>
using namespace std;
int Jos(int n, int k)
{
    if (n == 1)
        return 0;
    else
        return (Jos(n - 1, k) + k) % n;
}
int main()
{
    cout << Jos(5, 3) << endl;
    return 0;
}