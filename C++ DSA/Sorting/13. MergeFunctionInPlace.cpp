// ? Efficiently merging two sorted arrays with O(1) extra space

#include <iostream>
using namespace std;

// Calculating next gap
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

// Merging the subarrays using shell sorting
// Time Complexity: O(nlog n)
// Space Complexity: O(1)
void mergeInPlaceBetter(int nums[], int start, int end) // * Complexity->O(nlog n)
{
    int gap = end - start + 1;

    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        for (int i = start; i + gap <= end; i++)
        {
            int j = i + gap;
            if (nums[i] > nums[j])
                swap(nums[i], nums[j]);
        }
    }
}

void mergeInPlaceOP(int *a, int l, int m, int r) // * Complexity->O(n)
{
    int mx = max(a[m], a[r]) + 1;
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r && k <= r)
    {
        // recover back original element to compare
        int e1 = a[i] % mx;
        int e2 = a[j] % mx;
        if (e1 <= e2)
        {
            // update element by adding multiplication with new number
            a[k] += (e1 * mx);
            i++;
            k++;
        }
        else
        {
            // update element by adding multiplication with new number
            a[k] += (e2 * mx);
            j++;
            k++;
        }
    }

    // process those elements which are left in array a
    while (i <= m)
    {
        int el = a[i] % mx;
        a[k] += (el * mx);
        i++;
        k++;
    }

    while (j <= r)
    {
        int el = a[j] % mx;
        a[k] += (el * mx);
        j++;
        k++;
    }

    // finally update elements by dividing with maximum element
    for (int i = l; i <= r; i++)
        a[i] /= mx;
}

int main()
{
    int a[] = {1, 3, 5, 7, 2, 4, 6, 8};
    int n = *(&a + 1) - a;
    int l = 0, m = 3, r = 7;
    mergeInPlaceBetter(a, l, n);
    // mergeInPlaceOP(a, l, m, r);

    cout << "Array after merging" << endl;
    for (int x : a)
        cout << x << " ";

    return 0;
}