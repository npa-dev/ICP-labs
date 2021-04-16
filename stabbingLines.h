#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <fstream>

#define MAXARRAYSIZE 500

typedef int PointId;
typedef int LineId;

struct Point {
    PointId Pid;
    int x_cord;
    int y_cord;
};

struct Line{
    LineId Lid;
    PointId p1;
    PointId p2;
};

void readPoints(std::ifstream& inPutPointFile, Point pointsArray[], const int MaxPntsSize, int& numPoints);

void readLines(std::ifstream& inPutLineFile, Line linesArray[], const int MaxLnsSize, int& numLines);

void printLineByCoords(LineId lid, Line linesArray[], const int MaxLnsSize, Point pointsArray[], const int MaxPntsSize);

void getStabbedLines (const int xcoord, Line linesArray[], const int MaxLnsSize, const int NumLines, Point pointsArray[], const int MaxPtsSize, Line stabbedLines[], const int MaxStbSize, int& NumOfStbLines);