#include <iostream>
#include <vector>
using namespace std;
int majorityElementNoob(int *arr, int size)
{
    vector<int> res;
    for (int i = 0; i < size; i++)
    {
        int count = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > (size / 3))
            res.push_back(arr[i]);
    }

    return -1;
}

// * Boyer Moore's Voting Algorithm

vector<int> majorityElementOP(int *arr, int size)
{
    //? Find a maximum occuring element or candidate
    int count1 = 0, count2 = 0, num1 = -1, num2 = -1;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] == num1)
            count1++;
        else if (arr[i] == num2)
            count2++;
        else if (count1 == 0)
        {
            num1 = arr[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            num2 = arr[i];
            count2 = 1;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    //? Check if the candidate is actually a majority element
    vector<int> res;
    count1 = count2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == arr[num1])
            count1++;
        if (arr[i] == arr[num2])
            count2++;
    }
    if (count1 > (size / 3))
        res.push_back(num1);
    if (count2 > (size / 3))
        res.push_back(num2);
    return res;
}

int main()
{
    int arr[] = {8, 7, 6, 8, 6, 6, 6, 6};
    int size = 8;
    cout << majorityElementNoob(arr, size) << endl;
    vector<int> res = majorityElementOP(arr, size);
    for (int x : res)
        cout << x << " ";
    return 0;
}