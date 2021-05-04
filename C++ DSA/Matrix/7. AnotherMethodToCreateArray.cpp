class Matrix
{
    int *array;
    int m_width;

public:
    Matrix(int w, int h) : m_width(w), array(new int[w * h]) {}
    ~Matrix() { delete[] array; }
    int at(int x, int y) const { return array[index(x, y)]; }

    // protected:
    int index(int x, int y) const { return x + m_width * y; }
};

#include <iostream>
using namespace std;

int main()
{
    int m = 3, n = 2;
    Matrix arr(3, 2);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr.at(i, j) = 10;
            s
        }
    }

    return 0;
}