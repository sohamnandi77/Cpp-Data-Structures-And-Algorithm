#include <iostream>
using namespace std;

class ComplexNumber
{
private:
    int real, imaginary;

public:
    ComplexNumber(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    };

    void print()
    {
        cout << real << " + " << imaginary << "i" << endl;
    }

    void add(ComplexNumber const &c)
    {
        real += c.real;
        imaginary += c.imaginary;
    }
    void multiply(ComplexNumber const &c)
    {
        real = real * c.real - imaginary * c.imaginary;
        imaginary = real * c.imaginary + imaginary * c.real;
    }
};

int main()
{
    ComplexNumber c1(3, 4);
    ComplexNumber c2(5, 1);
    ComplexNumber c3(c1);

    c1.print();
    c2.print();
    c1.add(c2);
    c1.print();
    c3.multiply(c2);
    c3.print();
    return 0;
}