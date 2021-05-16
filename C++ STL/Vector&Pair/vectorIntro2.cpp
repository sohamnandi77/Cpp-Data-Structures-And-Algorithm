#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Dynamic Allocation
    vector<int> *vp = new vector<int>();
    delete vp;

    // Stactic Allocation
    vector<int> v;
    // push_back checks the capacity of the array
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    v[1] = 100;

    // ! Don't use [] for insert
    // * Use [] for get & update
    v[3] = 300;
    v[4] = 123;

    v.push_back(23);
    v.push_back(234);

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    cout << v[5] << endl;
    cout << v[6] << endl;

    cout << "Size: " << v.size() << endl;
    cout << v.at(2) << endl;
    //cout << v.at(6) << endl; //? at is safer to use

    // delete last element
    v.pop_back();

    // print the vector
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    // size and capacity
    vector<int> v2;
    for (int i = 0; i < 100; i++)
    {
        cout << "Capacity: " << v2.capacity() << endl;
        cout << "Size: " << v2.size() << endl;
        v2.push_back(i + 1);
    }

    return 0;
}