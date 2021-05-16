// ? Efficiently merging two sorted arrays with O(1) extra space

#include <iostream>
#include <algorithm>
using namespace std;

void mergeArrayNoob(int arr1[], int arr2[], int n, int m) // * Complexity -> O(n*m)
{

    // Now traverse the array1 and if
    // arr2 first element
    // is less than arr1 then swap
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] > arr2[0])
        {

            // Swap
            swap(arr1[i], arr2[0]);

            // After swaping we have to sort the array2
            // again so that it can be again swap with
            // arr1

            // We will store the firstElement of array2
            // and left shift all the element and store
            // the firstElement in arr2[k-1]
            int firstElement = arr2[0];

            int k;

            for (k = 1; k < m && arr2[k] < firstElement; k++)
                arr2[k - 1] = arr2[k];
            arr2[k - 1] = firstElement;
        }
    }
}

void mergeArrayBetter(int arr1[], int arr2[], int n, int m) // * Complexity -> O((n+m)*log(max(n+m)))
{
    int f = n - 1;
    int l = 0;
    while (f >= 0 && l < m)
    {
        if (arr1[f] >= arr2[l])
            swap(arr1[f], arr2[l]);
        f--;
        l++;
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

// Function to find next gap.
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void mergeArrayMoreBetter(int *arr1, int *arr2, int n, int m) // * Complexity -> O((n+m)*log(n+m))
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);

        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0;
             i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);

        if (j < m)
        {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
        }
    }
}

void mergeArrayOP(int arr1[], int arr2[], int n, int m) // * Complexity->O(n + m)
{
    int mx = 0;

    // increment one two avoid collision of 0 and maximum element of array in modulo operation
    mx = max(arr1[n - 1], arr2[m - 1]) + 1;
    int i = 0, j = 0, k = 0;
    while (i < n && j < m && k < (n + m))
    {
        // recover back original element to compare
        int e1 = arr1[i] % mx;
        int e2 = arr2[j] % mx;
        if (e1 <= e2)
        {
            // update element by adding multiplication with new number
            if (k < n)
                arr1[k] += (e1 * mx);
            else
                arr2[k - n] += (e1 * mx);
            i++;
            k++;
        }
        else
        {
            // update element by adding multiplication
            // with new number
            if (k < n)
                arr1[k] += (e2 * mx);
            else
                arr2[k - n] += (e2 * mx);
            j++;
            k++;
        }
    }

    // process those elements which are left in array arr1
    while (i < n)
    {
        int el = arr1[i] % mx;
        if (k < n)
            arr1[k] += (el * mx);
        else
            arr2[k - n] += (el * mx);
        i++;
        k++;
    }

    // process those elements which are left in array arr2
    while (j < m)
    {
        int el = arr2[j] % mx;
        if (k < n)
            arr2[k] += (el * mx);
        else
            arr2[k - n] += (el * mx);
        j++;
        k++;
    }

    // finally update elements by dividing with maximum element
    for (int i = 0; i < n; i++)
        arr1[i] /= mx;

    // finally update elements by dividing with maximum element
    for (int i = 0; i < m; i++)
        arr2[i] /= mx;
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int n1 = *(&arr1 + 1) - arr1;

    int arr2[] = {2, 4, 6, 8};
    int n2 = *(&arr2 + 1) - arr2;

    mergeArrayNoob(arr1, arr2, n1, n2);
    mergeArrayBetter(arr1, arr2, n1, n2);
    mergeArrayMoreBetter(arr1, arr2, n1, n2);
    mergeArrayOP(arr1, arr2, n1, n2);

    cout << "Array after merging" << endl;
    for (int i = 0; i < n1; i++)
        cout << arr1[i] << " ";
    cout << endl;
    for (int i = 0; i < n2; i++)
        cout << arr2[i] << " ";

    return 0;
}