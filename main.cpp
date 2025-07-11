/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 7/10/25
Instructor: Dave Harden
File: main.cpp

This program performs a basic arithmetic operation on two user-entered numbers.
The user inputs two numbers and an operator (+, -, *, or /). Based on the operator,
the program performs the operation and prints the result with two decimal places.
If an invalid operator is entered, the program prints an error message.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double firstUserNumber;
    double secondUserNumber;
    char userOperator;

    std::cout << "Enter first number: ";
    std::cin >> firstUserNumber;

    std::cout << "Enter an operator (+, -, *, or /): ";
    std::cin >> userOperator;

    std::cout << "Enter second number: ";
    std::cin >> secondUserNumber;

    std::cout << std::fixed << std::setprecision(2);

    switch (userOperator) {
        case '+':
            std::cout << "The answer is " << firstUserNumber + secondUserNumber
                << std::endl;
            break;
        case '-':
            std::cout << "The answer is " << firstUserNumber - secondUserNumber
                << std::endl;
            break;
        case '*':
            std::cout << "The answer is " << firstUserNumber * secondUserNumber
                << std::endl;
            break;
        case '/':
            std::cout << "The answer is " << firstUserNumber / secondUserNumber
                << std::endl;
            break;
        default:
            std::cout << "Please re-run the program and enter a valid operator."
                << std::endl;
    }

    return 0;
}