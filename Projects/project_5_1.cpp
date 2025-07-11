/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 7/11/25
Instructor: Dave Harden
File: main.cpp

This program converts a number of pounds entered by the user into ounces.
(1 pound = 16 ounces.) The program first asks if the user wants to convert.
If so, it enters a loop that repeatedly asks for pounds and prints the result
in ounces until the user chooses to stop.
*/

#include <iostream>
#include <iomanip>

constexpr int OUNCES_IN_POUND = 16;

int main() {
    char userChoice;
    int poundNumber;

    std::cout << "Is there a pounds to convert (Y or N)? ";
    std::cin >> userChoice;

    if (toupper(userChoice) == 'N') {
        return 0;
    }

    while (toupper(userChoice) != 'N') {
        std::cout << "enter pounds: ";
        std::cin >> poundNumber;

        std::cout << poundNumber << " pounds is "
            << poundNumber * OUNCES_IN_POUND << " ounces.";
        std::cout << std::endl;

        std::cout << "Is there another pounds to convert? ";
        std::cin >> userChoice;
    }

    return 0;
}