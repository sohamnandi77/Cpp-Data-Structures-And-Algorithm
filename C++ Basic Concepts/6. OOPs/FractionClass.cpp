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
    int getNumerator() { return numerator; }

    int getDenominator() { return denominator; }

    void setNumerator(int numerator) { this->numerator = numerator; }
    void setDenominator(int denominator) { this->denominator = denominator; }

    //? Member fuction will automatically interpret numerator and demnominator as of the  object
    //* numerator
    //* compiler interprets --> this -> numerator
    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }

    void simplyfy()
    {
        int gcd = 1;
        int j = min(numerator, denominator);
        for (int i = 1; i <= j; i++)
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                gcd = i;
            }
        }
        numerator /= gcd;
        denominator /= gcd;
    }
    void add(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = (x * numerator) + (y * f2.numerator);

        numerator = num;
        denominator = lcm;
        simplyfy();
    }

    void multiply(Fraction const &f2)
    {
        numerator *= f2.numerator;
        denominator *= f2.denominator;
        simplyfy();
    }

    ~Fraction(){};
};

int main()
{
    Fraction f1(10, 2);
    f1.print();
    Fraction f2(15, 4);
    f2.print();
    f1.add(f2);
    f1.print();

    Fraction f3(4, 3);
    f3.print();
    f3.multiply(f2);
    f3.print();
    return 0;
}