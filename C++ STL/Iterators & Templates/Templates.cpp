#include <iostream>
using namespace std;
template <typename T, typename V>
class Pair
{
    T x;
    V y;

public:
    void setX(T x) { this->x = x; }
    T getX() { return x; }
    void setY(V y) { this->y = y; }
    V getY() { return y; }
};
int main()
{
    Pair<int, double> p1;
    p1.setX(10);
    p1.setY(20.55);
    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<double, int> p2;
    p2.setX(10.59);
    p2.setY(20.55);
    cout << p2.getX() << " " << p2.getY() << endl;

    Pair<Pair<int, int>, int> p3;
    p3.setY(10);

    Pair<int, int> p4;
    p4.setX(15);
    p4.setY(16);

    p3.setX(p4);

    cout << p3.getX().getX() << endl;
    cout << p3.getX().getY() << endl;
    cout << p3.getY() << endl;

    return 0;
}