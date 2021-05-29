#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char a[1000];
    cin.get(); // * it consumes '\n' character

    int len = 0;
    int largest_len = 0;
    char largest[1000];
    for (int i = 0; i < n; i++)
    {
        cin.getline(a, 1000);
        // cout << a << endl;
        len = strlen(a);
        if (len > largest_len)
        {
            largest_len = len;
            strcpy(largest, a);
        }
    }
    cout << largest << " " << largest_len << endl;
    return 0;
}