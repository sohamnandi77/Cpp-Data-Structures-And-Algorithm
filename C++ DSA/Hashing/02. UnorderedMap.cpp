#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> m;
    m["courses"] = 15;
    m["gfg"] = 20;
    m["ide"] = 30;
    for (auto x : m)
        cout << x.first << " " << x.second << endl;

    // * Search in a map
    if (m.find("ide") != m.end())
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    auto it = m.find("ide");
    if (it != m.end())
        cout << (it->second) << endl;

    // * Another way to find
    if (m.count("ide") > 0)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    // * No of Key Value pair inside map
    cout << m.size() << endl;

    // * Remove a Key Value pair
    m.erase("ide");
    m.erase(m.begin());

    // * To remove Everything
    m.erase(m.begin(), m.end());
    return 0;
}