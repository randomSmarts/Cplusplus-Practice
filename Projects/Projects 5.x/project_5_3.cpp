/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 7/11/25
Instructor: Dave Harden
File: main.cpp

This program collects data from a group of moviegoers. For each person, the user
enters their age and food preference. The program classifies attendees into one
of five age groups, tracks the number of people in each group, and gathers food
preference data (popcorn, soda, or both). It also calculates and reports the
youngest and oldest attendee, as well as the average age. The program uses a
special-value loop and stops when a negative age is entered.
*/

#include <iostream>
#include <iomanip>

constexpr int AGE_RANGE_0 = 0;
constexpr int AGE_RANGE_1 = 18;
constexpr int AGE_RANGE_2 = 30;
constexpr int AGE_RANGE_3 = 40;
constexpr int AGE_RANGE_4 = 60;
constexpr int AGE_RANGE_INCREMENT = 1;

int main() {
    int inputtedAge;

    int peopleAgeRange1 = 0;
    int peopleAgeRange2 = 0;
    int peopleAgeRange3 = 0;
    int peopleAgeRange4 = 0;
    int peopleAgeRange5 = 0;

    int youngestPerson;
    int oldestPerson;

    double personCounter = 0;
    double ageCounter = 0;

    char foodPreference;

    int popcornCounter = 0;
    int sodaCounter = 0;
    int popcornAndSodaCounter = 0;

    std::cout << "Enter age of attendee (negative number to quit): ";
    std::cin >> inputtedAge;

    if (inputtedAge >= AGE_RANGE_0) {
        youngestPerson = inputtedAge;
        oldestPerson = inputtedAge;
    }
    else {
        std::cout << std::endl;
        std::cout << "No attendees were entered." << std::endl;
        return 0;
    }

    while (inputtedAge >= AGE_RANGE_0) {
        if (inputtedAge <= AGE_RANGE_1) {
            peopleAgeRange1 += 1;
        }
        else if (inputtedAge <= AGE_RANGE_2) {
            peopleAgeRange2 += 1;
        }
        else if (inputtedAge <= AGE_RANGE_3) {
            peopleAgeRange3 += 1;
        }
        else if (inputtedAge <= AGE_RANGE_4) {
            peopleAgeRange4 += 1;
        }
        else {
            peopleAgeRange5 += 1;
        }

        if (inputtedAge < youngestPerson) {
            youngestPerson = inputtedAge;
        }

        if (inputtedAge > oldestPerson) {
            oldestPerson = inputtedAge;
        }

        personCounter += 1;
        ageCounter += inputtedAge;

        std::cout << "Enter food preference ('p' for popcorn, "
                     "'s' for soda, 'b' for both): ";
        std::cin >> foodPreference;

        if (tolower(foodPreference) == 'p') {
            popcornCounter += 1;
        }
        else if (tolower(foodPreference) == 's') {
            sodaCounter += 1;
        }
        else if (tolower(foodPreference) == 'b') {
            popcornAndSodaCounter += 1;
        }
        else {
            std::cout << "Please input a valid preference.";
        }

        std::cout << "Enter age of attendee (negative number "
                     "to quit): ";
        std::cin >> inputtedAge;
    }

    std::cout << std::endl;

    std::cout << "age  " << AGE_RANGE_0 << " to " << AGE_RANGE_1
        << ": " << peopleAgeRange1 << std::endl;
    std::cout << "age " << AGE_RANGE_1 + AGE_RANGE_INCREMENT << " to "
        << AGE_RANGE_2 << ": " << peopleAgeRange2 << std::endl;
    std::cout << "age " << AGE_RANGE_2 + AGE_RANGE_INCREMENT << " to "
        << AGE_RANGE_3 << ": " << peopleAgeRange3 << std::endl;
    std::cout << "age " << AGE_RANGE_3 + AGE_RANGE_INCREMENT << " to "
        << AGE_RANGE_4 << ": " << peopleAgeRange4 << std::endl;
    std::cout << "over " << AGE_RANGE_4 << ": " << peopleAgeRange5
        << std::endl;

    std::cout << std::endl;

    std::cout << "food preference popcorn: " << popcornCounter
        << std::endl;
    std::cout << "food preference soda: " << sodaCounter
        << std::endl;
    std::cout << "food preference both: " << popcornAndSodaCounter
        << std::endl;

    std::cout << std::endl;

    std::cout << "The average age was " << std::fixed << std::setprecision(1)
        << ageCounter / personCounter << std::endl;
    std::cout << std::fixed << std::setprecision(0) <<
        "The youngest person in attendance was " << youngestPerson << std::endl;
    std::cout << std::fixed << std::setprecision(0) <<
        "The oldest person in attendance was " << oldestPerson << std::endl;

    return 0;
}