/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 7/10/25
Instructor: Dave Harden
File: main.cpp

This program calculates the cost of a phone call based on its start time and length.
The user enters a start time and a call duration in minutes. Based on when the call occurs
and how long it lasts, different discounts are applied. The program outputs both the gross
cost and the final net cost (after discounts and tax), formatted to two decimal places.
*/

#include <iostream>
#include <iomanip>

int main() {
    int startTime;
    int callLength;
    constexpr int eveningThreshold = 1800;
    constexpr int morningThreshold = 800;
    constexpr double federalTax = 1.04;
    constexpr double regularRate = 0.40;
    constexpr double lowerDiscount = 0.85;
    constexpr double higherDiscount = 0.5;
    constexpr double minuteThreshold = 60;

    std::cout << "Enter start time: ";
    std::cin >> startTime;

    std::cout << "Enter length of call in minutes: ";
    std::cin >> callLength;

    std::cout << std::fixed << std::setprecision(2);

    if (startTime <= morningThreshold || startTime >= eveningThreshold) {
        if (callLength > minuteThreshold) {
            std::cout << "The gross cost is $" << regularRate * callLength
                << std::endl;
            std::cout << "The net cost is $" << regularRate * callLength *
                higherDiscount * lowerDiscount * federalTax << std::endl;
        }
        else {
            std::cout << "The gross cost is $" << regularRate * callLength
                << std::endl;
            std::cout << "The net cost is $" << regularRate * callLength *
                higherDiscount * federalTax << std::endl;
        }
    }
    else {
        if (callLength > minuteThreshold) {
            std::cout << "The gross cost is $" << regularRate * callLength
                << std::endl;
            std::cout << "The net cost is $" << regularRate * callLength *
                lowerDiscount * federalTax << std::endl;
        }
        else {
            std::cout << "The gross cost is $" << regularRate * callLength
                << std::endl;
            std::cout << "The net cost is $" << regularRate * callLength *
                federalTax << std::endl;
        }
    }

    return 0;
}