#include <iostream>
using namespace std;
int FirstIndex(int arr[], int n, int x)
{
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] == x)
    {
      return i;
    }
  }
  return -1;
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = *(&arr + 1) - arr;
  int x = 5;
  cout << FirstIndex(arr, size, x) << endl;
  return 0;
}