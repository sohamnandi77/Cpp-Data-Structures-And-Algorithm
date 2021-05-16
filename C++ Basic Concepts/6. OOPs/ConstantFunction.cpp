#include <iostream>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    int getNumerator() const { return numerator; }

    int getDenominator() const { return denominator; }

    void setNumerator(int numerator)
    {
        this->numerator = numerator;
    }
    void setDenominator(int denominator)
    {
        this->denominator = denominator;
    }

    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }

    ~Fraction(){};
};

int main()
{
    Fraction f1(10, 2);
    Fraction f2(15, 4);

    Fraction const f3(20, 3); //? We can only call constant function using constant variables

    cout << f3.getNumerator() << " " << f3.getDenominator() << endl;

    return 0;
}