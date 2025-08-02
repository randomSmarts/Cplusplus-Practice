/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 7/28/25
Instructor: Dave Harden
File: main.cpp

//Fixme this description is wrong
This program quizzes the user on arithmetic problems and provides performance
feedback. The user specifies how many problems to attempt per set. The program
then presents three sets of problems: addition, subtraction, and multiplication.
For each set, the user can specify the maximum number used in the problems. The
program displays one problem at a time, checks whether the answer is correct,
and keeps track of the score for each set. At the end, it prints a report
showing the number of correct answers, total problems, and percentage accuracy
for each set and overall.
*/

#include <iostream>
using namespace std;

class Fraction
{
public:
    void set (int userNumerator, int userDenominator);

private:
    unsigned int numerator;
    unsigned int denominator;

};

void Fraction::set (int userNumerator, int userDenominator)
{
    numerator = userNumerator;
    denominator = userDenominator;
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
