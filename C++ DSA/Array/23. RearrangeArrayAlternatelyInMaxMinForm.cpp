// ? Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.

#include <iostream>
#define ll long long
using namespace std;

void rearrangeArray(ll arr[], int n)
{
    ll max_element = arr[n - 1] + 1;
    ll min = 0, i = 0;
    ll max = n - 1;
    while (min <= max)
    {
        if (i % 2 == 0)
        {
            arr[i] += (arr[max] % max_element) * max_element;
            max--;
        }
        else
        {
            arr[i] += (arr[min] % max_element) * max_element;
            min++;
        }
        i++;
    }
    for (ll i = 0; i < n; i++)
    {
        arr[i] /= max_element;
    }
}

int main()
{
    ll arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    rearrangeArray(arr, 8);
    for (ll x : arr)
    {
        cout << x << " ";
    }
    return 0;
}
