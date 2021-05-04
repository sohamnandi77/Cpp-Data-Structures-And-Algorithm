#include <iostream>
using namespace std;
int majorityElementNoob(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > size / 2)
            return i;
    }
    return -1;
}

// * Moore's Voting Algorithm

int majorityElementOP(int *arr, int size)
{
    //? Find a maximum occuring element or candidate
    int count = 1, res = 0;
    for (int i = 1; i < size; i++)
    {
        if (arr[res] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }

    //? Check if the candidate is actually a majority element
    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[res] == arr[i])
            count++;
    }
    if (count > size / 2)
        return res;
    else
        return -1;
}

int main()
{
    int arr[] = {8, 7, 6, 8, 6, 6, 6, 6};
    int size = 8;
    cout << majorityElementNoob(arr, size) << endl;
    cout << majorityElementOP(arr, size) << endl;
    return 0;
}