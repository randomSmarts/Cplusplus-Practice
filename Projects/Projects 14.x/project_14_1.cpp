/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 8/2/25
Instructor: Dave Harden
File: main.cpp
*/

#include <iostream>
using namespace std;

class Fraction
{
public:
    void set (int userNumerator, int userDenominator);
    void print ();
    Fraction addedTo (Fraction fraction);
    Fraction subtract (Fraction fraction);
    Fraction multipliedBy (Fraction fraction);
    Fraction dividedBy (Fraction fraction);
    bool isEqualTo (Fraction fraction);

private:
    unsigned int numerator = 0;
    unsigned int denominator = 0;
};






void Fraction::set (int userNumerator, int userDenominator)
{
    numerator = userNumerator;
    denominator = userDenominator;
}






void Fraction::print ()
{
    cout << numerator << "/" << denominator;
}






Fraction Fraction::addedTo (Fraction fraction)
{
    Fraction result{};
    result.denominator = fraction.denominator * denominator;
    result.numerator = fraction.denominator * numerator + denominator
        * fraction.numerator;
    return result;
}






Fraction Fraction::subtract (Fraction fraction)
{
    Fraction result{};
    result.denominator = fraction.denominator * denominator;
    result.numerator = fraction.denominator * numerator - denominator
        * fraction.numerator;
    return result;
}






Fraction Fraction::multipliedBy (Fraction fraction)
{
    Fraction result{};
    result.numerator = fraction.numerator * numerator;
    result.denominator = fraction.denominator * denominator;
    return result;
}






Fraction Fraction::dividedBy (Fraction fraction)
{
    Fraction result{};
    result.numerator = fraction.denominator * numerator;
    result.denominator = fraction.numerator * denominator;
    return result;
}






bool Fraction::isEqualTo (Fraction fraction)
{
    return (numerator * fraction.denominator == denominator *
        fraction.numerator);
}






int main()
{
    Fraction f1;
    Fraction f2;
    Fraction result;

    f1.set(9, 8);
    f2.set(2, 3);

    cout << "The product of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.multipliedBy(f2);
    result.print();
    cout << endl;

    cout << "The quotient of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.dividedBy(f2);
    result.print();
    cout << endl;

    cout << "The sum of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.addedTo(f2);
    result.print();
    cout << endl;

    cout << "The difference of ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << " is ";
    result = f1.subtract(f2);
    result.print();
    cout << endl;

    if (f1.isEqualTo(f2)){
        cout << "The two Fractions are equal." << endl;
    } else {
        cout << "The two Fractions are not equal." << endl;
    }
}