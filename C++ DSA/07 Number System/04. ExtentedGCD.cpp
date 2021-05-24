#include <iostream>
using namespace std;

class Triplet
{
public:
    int gcd, x, y;
};

int gcd(int a, int b)
{
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

Triplet gcdExtendedEuclid(int a, int b)
{
    // Base Case
    if (b == 0)
    {
        Triplet myAns;
        myAns.gcd = a;
        myAns.x = 1;
        myAns.y = 0;
        return myAns;
    }
    Triplet smallAns = gcdExtendedEuclid(b, a % b);
    Triplet myAns;
    myAns.gcd = smallAns.gcd;
    myAns.x = smallAns.y;
    myAns.y = smallAns.x - (a / b) * (smallAns.y);
    return myAns;
}

// Triplet gcdExtendedEuclidIterative(int a, int b)
// {

//     Triplet smallAns;
//     int r;
//     while (b > 0)
//     {
//         r = a % b;
//         a = b;
//         b = r;
//     }
// }

int main()
{
    int a = 12, b = 5;
    Triplet res = gcdExtendedEuclid(a, b);
    cout << res.gcd << endl;
    cout << res.x << endl;
    cout << res.y << endl;
    return 0;
}