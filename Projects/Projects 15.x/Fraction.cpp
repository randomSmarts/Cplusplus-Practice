/*
The Fraction class uses two private integer data members: numerator and
denominator, which represent the numerator and denominator of the rational
number respectively. All Fraction objects are guaranteed to be stored in
simplified form (lowest terms). The denominator is never zero (enforced by
the assertion in the parameterized constructor).
*/

#include <iostream>
#include <cassert>
#include <vector>
#include "../../Header Files/Projects 15.x/Fraction.h"
using namespace std;

constexpr int TWO = 2;
constexpr int NEGATIVE_ONE = -1;

Fraction::Fraction()
{
    numerator = 0;
    denominator = 1;
}






Fraction::Fraction(const int initialNumerator, const int initialDenominator)
{
    assert(initialDenominator != 0);

    numerator = initialNumerator;
    denominator = initialDenominator;
    simplify();
}






/*
Simplifies the fraction by repeatedly finding and dividing by common factors of
the numerator and denominator. Specifically, this method:
1. Handles the case where both numerator and denominator are negative by
    making them positive.
2. Finds all factors of numerator and denominator greater than or equal
    to 2 (as all real, positive numbers are having a factor of 1 which is not
    needed in this case).
3. Uses nested loops to find a single common factor, divides numerator and
    denominator by it, then repeats.
4. Does not use Euclid's algorithm.
5. Does not handle cases where the fraction is negative.
*/
void Fraction::simplify()
{
    bool negativeFractionChecker = true;

    if ((numerator >= 0 && denominator < 0) || (numerator < 0 &&
        denominator >= 0))
    {
        negativeFractionChecker = false;
    }

    if (negativeFractionChecker)
    {
        vector<int> numeratorFactors;
        vector<int> denominatorFactors;

        if (numerator < 0 && denominator < 0)
        {
            numerator *= NEGATIVE_ONE;
            denominator *= NEGATIVE_ONE;
        }

        for (int i = TWO; i <= numerator; i++)
        {
            if (numerator % i == 0)
            {
                numeratorFactors.push_back(i);
            }
        }

        for (int i = TWO; i <= denominator; i++)
        {
            if (denominator % i == 0)
            {
                denominatorFactors.push_back(i);
            }
        }

        bool simplifyChecker = true;

        while (simplifyChecker)
        {
            bool factorMatch = true;
            bool singleMatchNotFound = true;

            while (factorMatch)
            {
                for (const int numeratorFactor : numeratorFactors)
                {
                    for (const int denominatorFactor : denominatorFactors)
                    {
                        if (singleMatchNotFound)
                        {
                            if (numeratorFactor == denominatorFactor)
                            {
                                numerator /= numeratorFactor;
                                denominator /= denominatorFactor;

                                factorMatch = false;
                                singleMatchNotFound = false;
                            }
                        }
                    }
                }

                if (factorMatch)
                {
                    simplifyChecker = false;
                    factorMatch = false;
                }
            }

            bool simplifyCheckerStateChecker = true;

            if (!simplifyChecker)
            {
                simplifyCheckerStateChecker = false;
            }

            while (simplifyCheckerStateChecker)
            {
                numeratorFactors.clear();
                denominatorFactors.clear();

                for (int i = TWO; i <= numerator; i++)
                {
                    if (numerator % i == 0)
                    {
                        numeratorFactors.push_back(i);
                    }
                }

                for (int i = TWO; i <= denominator; i++)
                {
                    if (denominator % i == 0)
                    {
                        denominatorFactors.push_back(i);
                    }
                }

                simplifyCheckerStateChecker = false;
            }
        }
    }
}






void Fraction::print () const
{
    cout << numerator << "/" << denominator;
}






Fraction Fraction::addedTo (const Fraction& fraction) const
{
    Fraction result;
    result.denominator = fraction.denominator * denominator;
    result.numerator = fraction.denominator * numerator + denominator
        * fraction.numerator;
    result.simplify();
    return result;
}






Fraction Fraction::subtract (const Fraction& fraction) const
{
    Fraction result;
    result.denominator = fraction.denominator * denominator;
    result.numerator = fraction.denominator * numerator - denominator
        * fraction.numerator;
    result.simplify();
    return result;
}






Fraction Fraction::multipliedBy (const Fraction& fraction) const
{
    Fraction result;
    result.numerator = fraction.numerator * numerator;
    result.denominator = fraction.denominator * denominator;
    result.simplify();
    return result;
}






Fraction Fraction::dividedBy (const Fraction& fraction) const
{
    Fraction result;
    result.numerator = fraction.denominator * numerator;
    result.denominator = fraction.numerator * denominator;
    result.simplify();
    return result;
}






bool Fraction::isEqualTo (const Fraction& fraction) const
{
    return (numerator * fraction.denominator == denominator *
        fraction.numerator);
}