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

constexpr int EVENING_THRESHOLD = 1800;
constexpr int MORNING_THRESHOLD = 800;
constexpr double FEDERAL_TAX = 1.04;
constexpr double REGULAR_RATE = 0.40;
constexpr double LOWER_DISCOUNT = 0.85;
constexpr double HIGHER_DISCOUNT = 0.5;
constexpr double MINUTE_THRESHOLD = 60;

int main() {
    int startTime;
    int callLength;

    std::cout << "Enter start time: ";
    std::cin >> startTime;

    std::cout << "Enter length of call in minutes: ";
    std::cin >> callLength;

    std::cout << std::fixed << std::setprecision(2);

    if (startTime <= MORNING_THRESHOLD || startTime >= EVENING_THRESHOLD) {
        if (callLength > MINUTE_THRESHOLD) {
            std::cout << "The gross cost is $" << REGULAR_RATE * callLength
                << std::endl;
            std::cout << "The net cost is $" << REGULAR_RATE * callLength *
                HIGHER_DISCOUNT * LOWER_DISCOUNT * FEDERAL_TAX << std::endl;
        }
        else {
            std::cout << "The gross cost is $" << REGULAR_RATE * callLength
                << std::endl;
            std::cout << "The net cost is $" << REGULAR_RATE * callLength *
                HIGHER_DISCOUNT * FEDERAL_TAX << std::endl;
        }
    }
    else {
        if (callLength > MINUTE_THRESHOLD) {
            std::cout << "The gross cost is $" << REGULAR_RATE * callLength
                << std::endl;
            std::cout << "The net cost is $" << REGULAR_RATE * callLength *
                LOWER_DISCOUNT * FEDERAL_TAX << std::endl;
        }
        else {
            std::cout << "The gross cost is $" << REGULAR_RATE * callLength
                << std::endl;
            std::cout << "The net cost is $" << REGULAR_RATE * callLength *
                FEDERAL_TAX << std::endl;
        }
    }

    return 0;
}