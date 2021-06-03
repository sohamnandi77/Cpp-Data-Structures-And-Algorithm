#include <iostream>
#include <forward_list>
using namespace std;

// Forward List implement on Singly Linked List
int main()
{
    forward_list<int> l = {10, 15, 20};
    l.push_front(5); // insert 5 in the front of the list
    l.push_front(3);

    l.pop_front(); // remove 3 from the front of the list

    for (auto x : l)
        cout << x << "->";

    cout << endl;
    forward_list<int> m;
    m.assign({10, 15, 20, 30});
    m.remove(10); // remove all instances of 10

    for (auto it = m.begin(); it != m.end(); it++)
        cout << (*it) << "->";

    cout << endl;
    // * how to make a forward list from a another list
    m.assign(l.begin(), l.end());
    for (auto it = m.begin(); it != m.end(); it++)
        cout << (*it) << "->";

    cout << endl;

    forward_list<int> n;
    n.assign(5, 10);
    for (auto x : n)
        cout << x << "->";

    cout << endl;
    forward_list<int> l1 = {15, 20, 30};
    auto it = l1.insert_after(l1.begin(), 5);
    it = l1.insert_after(l1.begin(), {2, 3});

    it = l1.emplace_after(it, 40); // does the same things as insert

    it = l1.erase_after(it);
    for (auto x : l1)
        cout << x << "->";

    return 0;
}