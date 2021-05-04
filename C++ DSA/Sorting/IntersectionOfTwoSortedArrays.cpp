#include <iostream>
using namespace std;
void intersection(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (i > 0 && arr1[i - 1] == arr1[i])
        {
            i++;
            continue;
        }
        if (arr1[i] < arr2[j])
            i++;
        else if (arr1[i] > arr2[j])
            j++;
        else
        {
            cout << arr1[i] << endl;
            i++;
            j++;
        }
    }
}
int main()
{
    int a[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int b[] = {5, 10, 10, 15, 30};

    int m = *(&a + 1) - a;
    int n = *(&b + 1) - b;
    intersection(a, b, m, n);
    return 0;
}