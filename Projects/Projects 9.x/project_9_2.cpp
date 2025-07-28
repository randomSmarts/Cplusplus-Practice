/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 7/27/25
Instructor: Dave Harden
File: main.cpp

This program quizzes the user on arithmetic problems and provides performance
feedback. The user specifies how many problems to attempt per set. The program
then presents three sets of problems: addition, subtraction, and multiplication.
For each set, the user can specify the maximum number used in the problems. The
program displays one problem at a time, checks whether the answer is correct,
and keeps track of the score for each set. At the end, it prints a report
showing the number of correct answers, total problems, and percentage accuracy
for each set and overall.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void getMaxNum(int& maxNum);
void doOneSet(const char& equationSign, const int& probsPerSet,
    int& numCorrect);
void doOneProblem(const char& equationSign, const int& maxNum,
    int& numCorrect);
void printHeader(const char& equationSign);
void getProbsPerSet(int& probsPerSet);
void generateOperands(int& firstNum, int& secondNum, const int& maxNum);
void calculateCorrectAnswer(const int& firstNum, const int& secondNum,
    const char& equationSign, int& actualAnswer);
void checkAnswer(const int& userAnswer, const int& actualAnswer,
    int& numCorrect);
void printReport(const int& probsPerSet, const int& numCorrect1,
    const int& numCorrect2, const int& numCorrect3);

constexpr double PERCENTAGE_CONVERTER = 100.0;

int main() {
    int probsPerSet;
    int numCorrect1 = 0;
    int numCorrect2 = 0;
    int numCorrect3 = 0;

    //srand(static_cast<unsigned>(time(nullptr)));
    getProbsPerSet(probsPerSet);
    doOneSet('+', probsPerSet, numCorrect1);
    doOneSet('-', probsPerSet, numCorrect2);
    doOneSet('*', probsPerSet, numCorrect3);
    printReport(probsPerSet, numCorrect1, numCorrect2, numCorrect3);
}






/*
 * Displays the user's performance summary for all three sets. Uses probsPerSet
 * to compute percentages. Outputs results for addition (numCorrect1),
 * subtraction (numCorrect2), multiplication (numCorrect3), and the overall
 * total.
*/
void printReport(const int& probsPerSet, const int& numCorrect1,
    const int& numCorrect2, const int& numCorrect3) {
    cout << endl;

    cout << "Set#1:  You got " << numCorrect1 << " correct out of " <<
        probsPerSet << " for " << fixed << setprecision(1) <<
            static_cast<double>(numCorrect1) / static_cast<double>
        (probsPerSet) * PERCENTAGE_CONVERTER << "%" << endl;

    cout << "Set#2:  You got " << numCorrect2 << " correct out of " <<
        probsPerSet << " for " << fixed << setprecision(1) <<
            static_cast<double> (numCorrect2) / static_cast<double>
        (probsPerSet) * PERCENTAGE_CONVERTER << "%" << endl;

    cout << "Set#3:  You got " << numCorrect3 << " correct out of " <<
        probsPerSet << " for " << fixed << setprecision(1) <<
            static_cast<double> (numCorrect3) / static_cast<double>
        (probsPerSet) * PERCENTAGE_CONVERTER << "%" << endl;

    cout << "Overall you got " << numCorrect1 + numCorrect2 + numCorrect3
        << " correct out of " << probsPerSet + probsPerSet + probsPerSet <<
            " for " << fixed << setprecision(1 )<< static_cast<double>
        (numCorrect1 + numCorrect2 + numCorrect3) / static_cast<double>
        (probsPerSet + probsPerSet + probsPerSet) * PERCENTAGE_CONVERTER
        << "%" << endl;
}






/*
 * Prompts the user for the number of problems per set and stores the result
 * in probsPerSet. This determines how many problems will appear in each
 * arithmetic set.
 */
void getProbsPerSet(int& probsPerSet) {
    cout << "Enter problems per set: ";
    cin >> probsPerSet;
}






/*
 * Prints the header for the current problem set based on equationSign.
 * Displays "Set #" followed by a separator line to clearly indicate
 * which set is starting.
 */
void printHeader(const char& equationSign) {
    cout << endl;
    if (equationSign == '+')
    {
        cout << "Set #1" << endl;
        cout << "----------" << endl;
    }
    else if (equationSign == '-')
    {
        cout << "Set #2" << endl;
        cout << "----------" << endl;
    }
    else if (equationSign == '*')
    {
        cout << "Set #3" << endl;
        cout << "----------" << endl;
    }
}






/*
 * Asks the user to provide the maximum integer for the current set
 * of problems and stores the value in maxNum. This value determines
 * the range for operand generation.
*/
void getMaxNum(int& maxNum) {
    cout << "What is the maximum number for this set? ";
    cin >> maxNum;
}






/*
 * Runs through one complete set of arithmetic problems using the operator
 * specified by equationSign. Uses probsPerSet to control the number of
 * problems. Tracks correct answers in numCorrect and prompts the user for
 * maxNum before generating problems.
*/
void doOneSet(const char& equationSign, const int& probsPerSet,
    int& numCorrect) {
    int maxNum;

    numCorrect = 0;

    printHeader(equationSign);

    getMaxNum(maxNum);

    for (int i = 0; i < probsPerSet; i++)
    {
        doOneProblem(equationSign, maxNum, numCorrect);
    }
}






/*
 * Handles one arithmetic problem using equationSign as the operator and
 * maxNum to constrain operands. Displays the problem, reads the user
 * answer, and updates numCorrect if correct. Uses helper functions
 * for operand generation, answer calculation, and result checking.
*/
void doOneProblem(const char& equationSign, const int& maxNum,
    int& numCorrect) {
    int firstNum;
    int secondNum;
    int actualAnswer;
    int userAnswer;

    generateOperands(firstNum, secondNum, maxNum);
    cout << firstNum << " " << equationSign << " " << secondNum << " = ";
    calculateCorrectAnswer(firstNum, secondNum, equationSign, actualAnswer);
    cin >> userAnswer;
    checkAnswer(userAnswer, actualAnswer, numCorrect);
}






/*
 * Generates two random operands, firstNum and secondNum, each between 0 and
 * maxNum inclusive. These operands are later used to form an arithmetic
 * problem.
 */
void generateOperands(int& firstNum, int& secondNum, const int& maxNum) {
    firstNum = rand() % (maxNum + 1);
    secondNum = rand() % (maxNum + 1);
}






/*
 * Computes the correct result for an arithmetic expression using firstNum,
 * secondNum, and equationSign. Stores the computed value in actualAnswer
 * for later comparison with the user's input.
 */
void calculateCorrectAnswer(const int& firstNum, const int& secondNum,
    const char& equationSign, int& actualAnswer) {
    actualAnswer = 0;
    if (equationSign == '+')
    {
        actualAnswer = firstNum + secondNum;
    }
    else if (equationSign == '-')
    {
        actualAnswer = firstNum - secondNum;
    }
    else if (equationSign == '*')
    {
        actualAnswer = firstNum * secondNum;
    }
}






/*
 * Compares userAnswer to actualAnswer. Prints "correct" if they match,
 * otherwise prints "incorrect". Increments numCorrect when the user
 * answer is correct.
 */
void checkAnswer(const int& userAnswer, const int& actualAnswer,
    int& numCorrect) {
    if (userAnswer == actualAnswer)
    {
        cout << "correct" << endl;
        numCorrect += 1;
    }
    else
    {
        cout << "incorrect" << endl;
    }
}