/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 7/11/25
Instructor: Dave Harden
File: main.cpp

This program converts a number of pounds entered by the user into ounces
(1 pound = 16 ounces). The program uses a special-value loop that continues
to prompt the user for a number of pounds and prints the equivalent number
of ounces. The loop stops when the user enters any negative number.
*/

#include <iostream>
#include <iomanip>

constexpr int OUNCES_IN_POUND = 16;

int main() {
    int poundNumber;

    std::cout << "enter pounds (negative number to quit): ";
    std::cin >> poundNumber;

    while (poundNumber >= 0) {
        std::cout << poundNumber << " pounds is "
            << poundNumber * OUNCES_IN_POUND << " ounces.";
        std::cout << std::endl;

        std::cout << "enter pounds (negative number to quit): ";
        std::cin >> poundNumber;
    }

    return 0;
}