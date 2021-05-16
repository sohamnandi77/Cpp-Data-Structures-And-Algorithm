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
    Fraction operator+(Fraction const &f2) const
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = (x * numerator) + (y * f2.numerator);

        Fraction fNew(num, lcm);
        fNew.simplyfy();
        return fNew;
    }
    Fraction add(Fraction const &f2) const
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = (x * numerator) + (y * f2.numerator);

        Fraction fNew(num, lcm);
        fNew.simplyfy();
        return fNew;
    }

    Fraction operator*(Fraction const &f2) const
    {

        Fraction fNew(numerator * f2.numerator, denominator * f2.denominator);
        fNew.simplyfy();
        return fNew;
    }

    void multiply(Fraction const &f2)
    {
        numerator *= f2.numerator;
        denominator *= f2.denominator;
        simplyfy();
    }

    bool operator==(Fraction f2) const
    {
        return (numerator == f2.numerator && denominator == f2.denominator);
    }

    // * Unary operator Overloading

    // * Pre - increment
    Fraction &operator++()
    {
        numerator += denominator;
        simplyfy();
        return *this;
    }

    // * Post - increment
    Fraction operator++(int)
    {
        Fraction fNew(numerator, denominator);
        numerator += denominator;
        simplyfy();
        fNew.simplyfy();
        return fNew;
    }

    Fraction &operator+=(Fraction const &f2)
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = (x * numerator) + (y * f2.numerator);

        numerator = num;
        denominator = lcm;
        simplyfy();
        return *this;
    }

    ~Fraction(){};
};

int main()
{

    Fraction f1(10, 2);
    Fraction f2(15, 4);
    f1.print();
    f2.print();

    Fraction f3 = f1.add(f2);
    f3.print();

    Fraction f4 = f1 + f2;
    f4.print();

    Fraction f5 = f1 * f2;
    f5.print();

    if (f3 == f4)
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;

    f1.print();
    ++f1;
    f1.print();

    Fraction f6 = ++f1;
    f6.print();

    Fraction f7 = ++(++f1);
    f7.print();

    Fraction f8 = f1++;
    f1.print();
    f8.print();

    //! Nesting is not implemented in Post Increment -- (f1++)++

    Fraction f9(10, 3);
    Fraction f10(5, 2);
    f9.print();
    f10.print();
    (f9 += f10) += f10;
    f9.print();

    return 0;
}