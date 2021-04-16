void getStabbedLines (const int xcoord, Line linesArray[], const int MaxLnsSize, const int NumLines, Point pointsArray[], const int MaxPtsSize, Line stabbedLines[], const int MaxStbSize, int& NumOfStbLines){
    int count = 0;
    for(int i = 0; i < NumLines; i++){
        Line l = linesArray[i];
        Point start_point = pointsArray[l.p1];
        Point end_point = pointsArray[l.p2];
        if(end_point.x_cord > xcoord){
            if(start_point.x_cord < xcoord){
                if(count < MaxStbSize){
                    stabbedLines[count] = l;
                    count++;
                }
            }
        }
    }
    NumOfStbLines = count;
}