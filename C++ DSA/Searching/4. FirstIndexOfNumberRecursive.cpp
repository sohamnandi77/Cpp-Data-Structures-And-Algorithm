#include <iostream>
using namespace std;
int FirstIndex(int arr[], int low, int high, int x)
{
  if (low > high)
    return -1;
  int mid = (low + high) / 2;
  if (x > arr[mid])
    return FirstIndex(arr, mid + 1, high, x);
  else if (x < arr[mid])
    return FirstIndex(arr, low, mid - 1, x);
  else
  {
    if (mid == 0 || arr[mid - 1] != arr[mid])
      return mid;
    else
      return FirstIndex(arr, low, mid - 1, x);
  }
  return -1;
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 8, 8, 9, 10};
  int size = *(&arr + 1) - arr;
  int x = 8;
  cout << FirstIndex(arr, 0, size - 1, x) << endl;
  return 0;
}