#include <iostream>
using namespace std;
void intersectionNoob(int arr1[], int arr2[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (i > 0 && arr1[i] == arr1[i - 1])
            continue;
        for (int j = 0; j < n; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << arr1[i] << " ";
                break;
            }
        }
    }
    cout << endl;
}
void intersectionOP(int arr1[], int arr2[], int m, int n)
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
            cout << arr1[i] << " ";
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
    cout << "Noob Method" << endl;
    intersectionNoob(a, b, m, n);
    cout << "OP Method" << endl;
    intersectionOP(a, b, m, n);
    return 0;
}