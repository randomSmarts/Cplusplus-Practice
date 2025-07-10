/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 7/10/25
Instructor: Dave Harden
File: main.cpp

This program calculates and prints the area of either a square or a triangle, based on user input.
The user enters 's' for square or 't' for triangle, then provides the necessary dimensions.
The output is the area, printed with 1 decimal of precision.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    char figureType;
    double squareSide;
    double triangleBase;
    double triangleHeight;

    std::cout << "Enter the type of figure (s or t): ";
    std::cin >> figureType;

    if (tolower(figureType) == 's') {
        std::cout << "Enter the length of a side: ";
        std::cin >> squareSide;
        std::cout << std::fixed << std::setprecision(1)
            << "The area is " << pow(squareSide, 2.0) << std::endl;
    }
    else if (tolower(figureType) == 't') {
        std::cout << "Enter the base: ";
        std::cin >> triangleBase;
        std::cout << "Enter the height: ";
        std::cin >> triangleHeight;
        std::cout << "The area is " << std::fixed << std::setprecision(1)
            << 0.5 * triangleBase * triangleHeight << std::endl;
    }
    else {
        std::cout << "Please re-run the program and enter a correct character, thank you!" << std::endl;
    }

    return 0;
}