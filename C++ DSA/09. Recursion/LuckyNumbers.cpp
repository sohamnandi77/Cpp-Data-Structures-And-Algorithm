#include <iostream>
using namespace std;
bool isLucky(int n, int &counter)
{
    if (counter <= n)
    {

        if (n % counter == 0)
        {
            return false;
        }
        n = n - n / counter;
        counter++;
        return isLucky(n, counter);
    }
    else
        return true;
}
int main()
{
    int n = 3;
    int counter = 2;
    cout << isLucky(n, counter) << endl;

    return 0;
}