#include <iostream>
#include <vector>
using namespace std;

bool isPal(string &str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int palPartition(string &s, int i, int j)
{
    // Base Case:
    // already a palindrome
    if (i >= j)
        return 0;

    // check if the string is palindrom or not for zero partition
    if (isPal(s, i, j))
        return 0;

    int ans = INT_MAX;

    for (int k = i; k < j; k++)
    {
        // calculate temp ans

        int temp = palPartition(s, i, k) + palPartition(s, k + 1, j) + 1;
        ans = min(ans, temp);
    }

    return ans;
}

int main()
{
    string s = "nitinyn";
    int n = s.length();
    cout << palPartition(s, 0, n - 1) << endl;
    return 0;
}