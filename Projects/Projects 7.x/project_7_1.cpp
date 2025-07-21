/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 7/15/25
Instructor: Dave Harden
File: main.cpp

This program reads a series of integers from the user and determines the
positions of the first and last occurrences of the number 7. The user
specifies how many numbers will be entered and then inputs each number.
If the number 7 appears, the program reports the positions of its first
and last appearances; otherwise, it displays a message that no 7 was '
entered. All output is printed to the console.
*/

#include <iostream>
#include <iomanip>

using namespace std;

constexpr int POSITION_NUMBER_CHOSEN = 7;
constexpr int POSITION_CHECKER = -9999;

const string FIRST_NUMBER_POSITION_P1 = "The first ";
const string FIRST_NUMBER_POSITION_P2 = " was in position ";
const string LAST_NUMBER_POSITION_P1 = "The last ";
const string LAST_NUMBER_POSITION_P2 = " was in position ";
const string NO_NUMBER_POSITION_P1 = "Sorry, no ";
const string NO_NUMBER_POSITION_P2 = "'s were entered.";

int main() {
    int numbersEntered;
    int userNum;
    int firstPosition = POSITION_CHECKER;
    int lastPosition = POSITION_CHECKER;

    cout << "How many numbers will be entered? ";
    cin >> numbersEntered;

    for (int i = 0; i < numbersEntered; i++) {
        cout << "Enter num: ";
        cin >> userNum;

        if (userNum == POSITION_NUMBER_CHOSEN &&
            (firstPosition == POSITION_CHECKER || i < firstPosition)) {
            firstPosition = i + 1;
        }

        if (userNum == POSITION_NUMBER_CHOSEN &&
            (lastPosition == POSITION_CHECKER || i > lastPosition - 1)) {
            lastPosition = i + 1;
        }
    }

    if (firstPosition == POSITION_CHECKER || lastPosition ==
        POSITION_CHECKER) {
        cout << NO_NUMBER_POSITION_P1 << POSITION_NUMBER_CHOSEN
            << NO_NUMBER_POSITION_P2 << endl;
    }
    else {
        cout << FIRST_NUMBER_POSITION_P1 << POSITION_NUMBER_CHOSEN
            << FIRST_NUMBER_POSITION_P2 << firstPosition << endl;
        cout << LAST_NUMBER_POSITION_P1 << POSITION_NUMBER_CHOSEN
            << LAST_NUMBER_POSITION_P2 << lastPosition << endl;
    }

    return 0;
}