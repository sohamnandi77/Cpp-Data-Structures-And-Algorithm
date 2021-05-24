#include <iostream>
#include <vector>
using namespace std;
vector<int> majorityElementNoob(int *arr, int size)
{
    vector<int> res;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > (size / 3))
        {
            res.push_back(i);
            count = 0;
        }
    }

    if (res.size() != 2)
    {
        res.clear();
        res.push_back(-1);
    }
    return res;
}

// * Boyer Moore's Voting Algorithm

vector<int> majorityElementOP(int *arr, int size)
{
    //? Find a maximum occuring element or candidate
    int count1 = 1, count2 = 1, num1 = 0, num2 = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[num1] == arr[i])
            count1++;
        else if (arr[num2] == arr[i])
            count2++;
        else if (count1 == 0)
        {
            num1 = i;
            count1 = 1;
        }
        else if (count2 == 0)
        {
            num2 = i;
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
    if (res.size() != 2)
    {
        res.clear();
        res.push_back(-1);
    }
    return res;
}

int main()
{
    int arr[] = {7, 8, 9, 7, 6, 8, 6, 6};
    int size = 8;
    cout << "Noob Method" << endl;
    vector<int> res1 = majorityElementNoob(arr, size);
    for (int x : res1)
        cout << x << " ";
    cout << endl;
    cout << "OP Method" << endl;
    vector<int> res = majorityElementOP(arr, size);
    for (int x : res)
        cout << x << " ";
    return 0;
}