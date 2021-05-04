#include <iostream>
using namespace std;
void TowerOfHanoi(int NoOfDisk, char A = 'A', char B = 'B', char C = 'C')
{
    if (NoOfDisk == 1)
    {
        cout << "Move 1 from " << A << " to " << C << endl;
        return;
    }
    TowerOfHanoi(NoOfDisk - 1, A, C, B);
    cout << "Move " << NoOfDisk << " from " << A << " to " << C << endl;
    TowerOfHanoi(NoOfDisk - 1, B, A, C);
}
int main()
{
    TowerOfHanoi(3);
    return 0;
}