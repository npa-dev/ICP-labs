#include "stabbingLines.h"
#include "readPoints.cpp"
#include "readLines.cpp"
#include "printLineByCoords.cpp"
#include "getStabbedLines.cpp"

using namespace std;

int main(){

    const int maxPoints = MAXARRAYSIZE;
    const int maxLines = MAXARRAYSIZE;
    const int maxStbSize = MAXARRAYSIZE;

    // Creating arrays for the points, lines and stabbed lines, and and declaring variables for their lengths
    Point points[MAXARRAYSIZE];
    int pointsLen;
    Line lines[MAXARRAYSIZE];
    int linesLen;
    Line stabbedLines[MAXARRAYSIZE];
    int lenStabbedLines;

    const int xcoord = 5;

    //Creating the input streams to help in the reading of the files
    std::ifstream pointsInput, linesInput;
    readPoints(pointsInput, points, maxPoints, pointsLen);
    readLines(linesInput, lines, maxLines, linesLen);
    //Printing all the lines
    std::cout << "\nThe lines as read from the Point and Line files are: " << std::endl;
    for(int i = 0; i < linesLen; i ++){
        printLineByCoords(i, lines, maxLines, points, maxPoints);
    }
    //Get the stabbed lines
    getStabbedLines (xcoord,lines, maxLines, linesLen, points, maxPoints, stabbedLines, maxStbSize, lenStabbedLines);

    //Printing out the stabbed lines
    std::cout << "\nThe stabbed lines are: " << std::endl;
    for(int i = 0; i < lenStabbedLines; i ++){
        printLineByCoords(stabbedLines[i].Lid, stabbedLines, maxStbSize, points, maxPoints);
    }

   


    return 0;
}

