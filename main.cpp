/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 7/15/25
Instructor: Dave Harden
File: main.cpp

This program repeatedly prompts the user to enter the name of a text file and
counts the number of words in that file. If the file opens successfully, the
program displays the total word count; otherwise, it displays an error message.
The user can continue entering filenames, and the program terminates when the
user enters "quit". All results are printed to the console.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string userInput;
    string currentWord;
    ifstream inputFile;
    int numberOfWords = 0;

    cout << "Enter the filename: ";
    cin >> userInput;

    while (userInput != "quit") {
        inputFile.open(userInput);

        if (inputFile) {
            while (inputFile >> currentWord) {
                numberOfWords += 1;
            }

            cout << "The file has " << numberOfWords << " words." << endl;
        }
        else {
            cout << "Couldn't open file." << endl;
        }

        numberOfWords = 0;
        inputFile.close();

        cout << "Enter the filename: ";
        cin >> userInput;
    }

    return 0;
}