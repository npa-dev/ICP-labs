
#include <fstream>

void readLines(std::ifstream& inPutLineFile, Line linesArray[], const int MaxLnsSize, int& numLines){
    std::string linesFile = "Lines.txt";
    inPutLineFile.open(linesFile);
    if (!inPutLineFile)
    {
        std::cerr << " Sorry we could not read the lines from the file" << std::endl;
        return;
    }
    // Reading from the file.
    std::string lid, p1, p2;
    int count = 0;
    while (inPutLineFile >> lid >> p1 >> p2){
        Line l; 
        l.Lid = stoi(lid);
        l.p1 = stoi(p1);
        l.p2 = stoi(p2);
        if(count < MaxLnsSize){
            linesArray[count] = l;
            count++;
        }
    }
    numLines = count;
}