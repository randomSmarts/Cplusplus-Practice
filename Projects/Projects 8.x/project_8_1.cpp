/*
Name: Aarsh Mittal
Class: C S -002A-02W
Date: 7/23/25
Instructor: Dave Harden
File: main.cpp

This program draws a customizable ASCII rocket on the console. The user is
prompted to enter three values: the width of each stage (stageWidth), the
height of each stage (stageHeight), and the number of stages (stageNumber).
Using these values, the program constructs a rocket consisting of a cone at
the top, one or more rectangular stages, and a cone at the bottom. The cones
automatically adjust their shape to match the given width. Output is
displayed in the console using helper functions that handle the drawing of
cones, horizontal lines, vertical lines, and box shapes.
*/

#include <iostream>
#include <fstream>

using namespace std;

void getDimensions (int& stageWidth, int& stageHeight, int& stageNumber);
void drawHorizontalLine(int numXs);
void drawOneRow(int numSpaces);
void draw2VerticalLines(int numSpaces, int numRows);
void printSpacesBeforeX (int middle, int numSpaces);
void printX ();
void printSpacesBetweenX (int numSpaces);
void drawCone (int stageWidth);
void drawBox(int width, int height);
void drawRocket(int stageWidth, int stageHeight, int stageNumber);

constexpr int TWO = 2;

int main() {
    int stageWidth;
    int stageHeight;
    int stageNumber;

    getDimensions(stageWidth, stageHeight, stageNumber);
    drawRocket(stageWidth, stageHeight, stageNumber);
}






/*
getDimensions prompts the user to enter three values: stageWidth, stageHeight,
and stageNumber. It stores these values in the reference parameters provided.
stageWidth represents the width of each rocket stage, stageHeight is the height
of each stage, and stageNumber specifies how many stages the rocket will have.
*/
void getDimensions (int& stageWidth, int& stageHeight, int& stageNumber) {
    cout << "enter width: ";
    cin >> stageWidth;

    cout << "enter height of each stage: ";
    cin >> stageHeight;

    cout << "enter number of stages: ";
    cin >> stageNumber;
}






void drawHorizontalLine(int numXs) {
    for (int count = 0; count < numXs; count++){
        cout << "X";
    }
    cout << endl;
}






void drawOneRow(int numSpaces) {
    cout << "X";
    for (int spaceCount = 0; spaceCount < numSpaces; spaceCount++){
        cout << " ";
    }
    cout << "X" << endl;
}






void draw2VerticalLines(int numSpaces, int numRows) {
    for (int rowCount = 0; rowCount < numRows; rowCount++){
        drawOneRow(numSpaces);
    }
}






/*
printSpacesBeforeX prints a series of spaces before the first 'X' in a cone row.
The parameter middle represents the horizontal center point of the cone, while
numSpaces indicates the current spacing between the two 'X' characters. This
function ensures proper alignment of the cone shape by adding leading spaces.
*/
void printSpacesBeforeX (int middle, int numSpaces) {
    for (int j = 1; j < (middle - (numSpaces / TWO)); j++) {
        cout << " ";
    }
}






/*
printX outputs a single 'X' character to the console without adding any spaces
or newlines. It is used to draw the edges of the cone and box components of
the rocket.
*/
void printX () {
    cout << "X";
}






/*
printSpacesBetweenX prints a sequence of spaces between two 'X' characters in a
cone row. The parameter numSpaces specifies how many spaces should be printed
to create the correct shape and spacing for the cone.
*/
void printSpacesBetweenX (int numSpaces) {
    for (int l = 0; l < numSpaces; l++) {
        cout << " ";
    }
}






/*
drawCone outputs a cone for the rocket, adjusting its shape based on the given
stageWidth (the width of each stage). The function uses loops to calculate the
proper number of spaces and 'X' characters for each row, ensuring the cone is
centered and aligned with the rocket's width.
*/
void drawCone (const int stageWidth) {
    int numRows;

    if (stageWidth % TWO == 0) {
        numRows = stageWidth / TWO;
        int middle = stageWidth / TWO;
        int numSpaces = 0;

        for (int i = 0; i < numRows; i++) {
            printSpacesBeforeX(middle, numSpaces);

            printX();

            printSpacesBetweenX(numSpaces);

            printX();

            numSpaces += TWO;

            cout << endl;
        }
    }
    else {
        numRows = stageWidth / TWO + 1;
        int middle = stageWidth / TWO + 1;
        int numSpaces = 0;
        int j;

        for (int i = 0; i < numRows; i++) {
            for (j = 1; j < middle - numSpaces; j++) {
                cout << " ";
            }

            if (i == 0) {
                printX();
            }
            else {
                printX();
                for (int k = j + TWO; k <= middle + numSpaces; k++) {
                    cout << " ";
                }
                printX();
            }

            numSpaces += 1;

            cout << endl;
        }
    }
}






void drawBox(const int width, const int height) {
    drawHorizontalLine(width);
    draw2VerticalLines(width - TWO, height - TWO);
    drawHorizontalLine(width);
}






/*
drawRocket creates the complete rocket using the dimensions provided by the
user. It first calls drawCone to print the top cone, then calls drawBox
stageNumber times to create the rectangular stages, and finally calls
drawCone again to print the bottom cone. The parameter stageWidth specifies
the width of each stage, stageHeight specifies the height of each stage, and
stageNumber determines how many stages the rocket will include.
*/
void drawRocket(const int stageWidth, const int stageHeight,
    const int stageNumber) {
    drawCone(stageWidth);

    for (int i = 0; i < stageNumber; i++) {
        drawBox(stageWidth, stageHeight);
    }

    drawCone(stageWidth);
}