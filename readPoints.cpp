#ifndef STABBINGLINES_H
#define STABBINGLINES_H

void readPoints(std::ifstream& inPutPointFile, Point pointsArray[], const int MaxPntsSize, int& numPoints){
    std::string pointsFile = "Points.txt";
    inPutPointFile.open(pointsFile);
    if (!inPutPointFile)
    {
        std::cerr << " Sorry we could not read the points from the file" << std::endl;
        return;
    }
    // Reading from the file.
    std::string pid, x, y;
    int count = 0;
    while (inPutPointFile >> pid >> x >> y){
        Point p; 
        p.Pid = stoi(pid);
        p.x_cord = stoi(x);
        p.y_cord = stoi(y);
        if(count < MaxPntsSize){
            pointsArray[count] = p;
            count++;
        }
    }
    numPoints = count;
}

#endif