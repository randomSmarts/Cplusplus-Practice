/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 8/5/25
Instructor: Dave Harden
File: Fraction.h

The Fraction class represents rational numbers using a numerator and a
denominator. It supports arithmetic operations (add, subtract, multiply,
divide), equality checking, and ensures that every Fraction is stored in
simplified form at all times (if the fraction is non-negative).

Fraction();

pre: An object is instantiated correctly with no arguments passed through.
post: The numerator is set to 0, and the denominator is set to 1, creating a
        Fraction equal to 0/1

Fraction(int initialNumerator, int initialDenominator);

pre: An object is instantiated correctly with two arguments passed through, in
        which the initialDenominator must not be 0
post: Constructs a Fraction with the given numerator and denominator, reduced
        to lowest terms

void print() const;

pre: An object is instantiated correctly
post: Outputs the Fraction stored in the object in the form
        (numerator/denominator)

Fraction addedTo(const Fraction& fraction) const;

pre: The fraction object passed-by-reference is instantiated correctly
post: Returns a new Fraction that is the sum of the calling object and the
        parameter, simplified

Fraction subtract(const Fraction& fraction) const;

pre: The fraction object passed-by-reference is instantiated correctly
post: Returns a new Fraction that is the difference of the calling object minus
        the parameter, simplified

Fraction multipliedBy(const Fraction& fraction) const;

pre: The fraction object passed-by-reference is instantiated correctly
post: Returns a new Fraction that is the product of the calling object and the
        parameter, simplified

Fraction dividedBy(const Fraction& fraction) const;

pre: The fraction object passed-by-reference is instantiated correctly and the
        numerator of the parameter must not be 0
post: Returns a new Fraction that is the quotient of the calling object divided
        by the parameter, simplified

bool isEqualTo(const Fraction& fraction) const;

pre: The fraction object passed-by-reference is instantiated correctly
post: Returns true if the calling Fraction and the parameter represent the same
        rational value (the same fraction), otherwise false
*/

#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
public:
    Fraction();
    Fraction(int initialNumerator, int initialDenominator);
    void print () const;
    Fraction addedTo (const Fraction& fraction) const;
    Fraction subtract (const Fraction& fraction) const;
    Fraction multipliedBy (const Fraction& fraction) const;
    Fraction dividedBy (const Fraction& fraction) const;
    bool isEqualTo (const Fraction& fraction) const;

private:
    int numerator;
    int denominator;
    void simplify();
};

#endif //FRACTION_H