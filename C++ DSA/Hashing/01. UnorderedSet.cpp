#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s;

    // * insert
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);
    s.insert(5); // * this insert will be ignored as it key already exists

    for (int x : s)
        cout << x << endl;

    // * begin & end
    for (auto it = s.begin(); it != s.end(); it++)
        cout << (*it) << endl;

    // * find
    if (s.find(15) == s.end())
        cout << "Not Found" << endl;
    else
        cout << "Found " << *(s.find(15)) << endl;

    // * count
    if (s.count(15))
        cout << "Found" << endl;
    else
        cout << "Found" << endl;

    // * size
    cout << s.size() << endl;

    // * erase
    s.erase(15);
    cout << s.size() << endl;

    // * another way to erase
    auto it = s.find(10);
    s.erase(it);
    cout << s.size() << endl;

    // *  to erase everything
    s.erase(s.begin(), s.end());

    // * clear
    s.clear();
    cout << s.size() << endl;

    return 0;
}