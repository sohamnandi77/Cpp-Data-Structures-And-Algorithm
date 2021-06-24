#include <iostream>
using namespace std;

int main()
{
    string S = "ddd";
    cin >> S;
    string res = "";
    int arr[26] = {0};
    for (int i = 0; i < S.length(); i++)
        arr[(int)S[i] - 97] += 1;

    int check[26] = {0};
    for (int i = 0; i < S.length(); i++)
    {
        int x = (int)S[i] - 97;
        check[x] += 1;
        if ((arr[x] % 2 == 0) && check[x] != arr[x] / 2 && check[x] != arr[x] / 2 + 1)
            res = res + S[i];
        else if (arr[x] % 2 != 0 && check[x] != arr[x] / 2 + 1)
            res = res + S[i];
    }
    cout << res << endl;
}