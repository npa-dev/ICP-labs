void printLineByCoords(LineId lid, Line linesArray[], const int MaxLnsSize, Point pointsArray[], const int MaxPntsSize){
    // The function will output the information about the line in the format: Line <lindeid>: (<start_x>, <start_y>) ---> (<end_x>, <end_y>). 
    Line l = linesArray[lid];
    Point start_point = pointsArray[l.p1];
    Point end_point = pointsArray[l.p2];
    std::cout << "Line:" << lid << " (" << start_point.x_cord << ", " << start_point.y_cord << ")" << " ---> (" << end_point.x_cord << ", " << end_point.y_cord << ")" << std::endl;
}