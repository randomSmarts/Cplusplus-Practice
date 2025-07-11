/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 7/10/25
Instructor: Dave Harden
File: main.cpp

This program takes an integer input representing the number of years of school completed.
Based on the input, it prints whether the person is in elementary school, middle school,
high school, college, has had no school, or submitted an invalid response.
The output is a simple classification string.
*/

#include <iostream>
#include <iomanip>

constexpr int ELEMENTARY_SCHOOL_END = 6;
constexpr int MIDDLE_SCHOOL_END = 8;
constexpr int HIGH_SCHOOL_END = 12;

int main() {
    int yearsOfSchool;

    std::cout << "Enter number of years of school: ";
    std::cin >> yearsOfSchool;

    if (yearsOfSchool < 0) {
        std::cout << "years of school must be a non-negative integer" << std::endl;
    }
    else if (yearsOfSchool == 0) {
        std::cout << "no school" << std::endl;
    }
    else if (yearsOfSchool <= ELEMENTARY_SCHOOL_END) {
        std::cout << "elementary school" << std::endl;
    }
    else if (yearsOfSchool <= MIDDLE_SCHOOL_END) {
        std::cout << "middle school" << std::endl;
    }
    else if (yearsOfSchool <= HIGH_SCHOOL_END) {
        std::cout << "high school" << std::endl;
    }
    else {
        std::cout << "college" << std::endl;
    }

    return 0;
}