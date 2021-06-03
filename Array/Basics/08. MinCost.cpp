// Ramu often uses public transport. The transport in the city is of two types: cabs and rickshaws. The city has n rickshaws and m cabs, the rickshaws are numbered by integers from 1 to n, the cabs are numbered by integers from 1 to m.
// Public transport is not free. There are 4 types of tickets:

// * A ticket for one ride on some rickshaw or cab. It costs c1 ruppees;
// * A ticket for an unlimited number of rides on some rickshaw or on some cab. It costs c2 ruppees;
// * A ticket for an unlimited number of rides on all rickshaws or all cabs. It costs c3 ruppees;
// * A ticket for an unlimited number of rides on all rickshaw and cabs. It costs c4 ruppees.

// Ramu knows for sure the number of rides he is going to make and the transport he is going to use. He asked you for help to find the minimum sum of ruppees he will have to spend on the tickets.

// Input Format : Each Test case has 4 lines which are as follows :
// The first line contains four integers c1, c2, c3, c4(1 <= c1, c2, c3, c4 <= 1000) - the costs of the tickets.
// The second line contains two integers n and m(1 <= n,m <= 1000) - the number of rickshaws and cabs Ramu is going to use.
// The third line contains n integers ai(0 <= ai <= 1000) - the number of times Ramu is going to use the rickshaw number i.
// The fourth line contains m integers bi(0 <= bi <= 1000) - the number of times Ramu is going to use the cab number i.

// Output Format : Print a single number - the minimum sum of ruppees Ramu will spend on the tickets.

#include <iostream>
using namespace std;

int minCost(int c1, int c2, int c3, int c4, int *n1, int n, int *m1, int m)
{
    // Rickshaw
    int cost_r = 0;
    for (int i = 0; i < n; i++)
        cost_r += min(n1[i] * c1, c2);
    cost_r = min(cost_r, c3);

    // Cabs
    int cost_c = 0;
    for (int i = 0; i < m; i++)
        cost_c += min(m1[i] * c1, c2);
    cost_c = min(cost_c, c3);

    return min(cost_c + cost_r, c4);
}

int main()
{

    int c1 = 1, c2 = 3, c3 = 7, c4 = 19;
    int n = 2, m = 3;
    int n1[] = {2, 5};
    int m1[] = {4, 4, 4};

    cout << minCost(c1, c2, c3, c4, n1, n, m1, m) << endl;
    return 0;
}