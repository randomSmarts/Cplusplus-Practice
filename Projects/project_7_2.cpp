/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 7/15/25
Instructor: Dave Harden
File: main.cpp

This program repeatedly prompts the user to enter a positive integer and
calculates the sum of the squares of all integers from 1 up to that number.
For example, if the user enters 4, the program computes 1² + 2² + 3² + 4².
The program uses a loop to handle multiple inputs and terminates when the
user enters 0 or a negative number. All results are printed to the console.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int userInput;
    int squareSum = 0;

    cout << "Enter an integer larger than 0 (0 or less to quit): ";
    cin >> userInput;

    while (userInput > 0) {
        for (int i = 1; i <= userInput; i++) {
            squareSum += (i*i);
        }

        cout << "The sum of the squares from 1 to " << userInput << " is "
            << squareSum << endl;

        cout << "Enter an integer larger than 0 (0 or less to quit): ";
        cin >> userInput;

        squareSum = 0;
    }

    return 0;
}