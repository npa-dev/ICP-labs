// By: Oliver Ngong and Precious Njeck
#include "classFile.cpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    // Defining an array of rectBlocks
    vector<Rectblocks> arr; 

    //Reading the data from the file and creating rectBlock objects
    string datafile = "dataBlocks.dat";
    ifstream inPutPointFile;
    inPutPointFile.open(datafile);
    if(!inPutPointFile)
    {
        cerr << " Sorry we could not read the data from the file" << endl;
    }

    string Width, Height, Length;
    while (inPutPointFile >> Width >> Height >> Length){ 
        Rectblocks R(stoi(Width), stoi(Height), stoi(Length));
        arr.push_back(R);  
    }
     
    cout << "The rectangular blocks have been read into an array. There are " << arr.size() << " of them\n" << endl;

    // Generating an array of square rects
    vector<SqrBaseRectBlocks> sqrArr;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i].Width == arr[i].Height){
            SqrBaseRectBlocks S(arr[i].Width, arr[i].Height, arr[i].Length);
            sqrArr.push_back(S);
        }
    }
    cout << "The square base rectangular blocks have been read into an array. There are " << sqrArr.size() << " of them\n" << endl;

    // Generating an array of the cuboid blocks
    vector<CubiodBlocks> cubArr;
    for(int i = 0; i < sqrArr.size(); i++){
        if(sqrArr[i].Width == sqrArr[i].Height && sqrArr[i].Width == sqrArr[i].Length){
            CubiodBlocks C(sqrArr[i].Width, sqrArr[i].Height, sqrArr[i].Length);
            cubArr.push_back(C);
        }
    }
    cout << "The cuboid rectangular blocks have been read into an array. There are " << cubArr.size() << " of them\n" << endl;

    // Generating an array of cylindrical blocks
    vector<CylindricalBlocks> cylArr;
    for(int i = 0; i < sqrArr.size(); i++){
            CylindricalBlocks C(sqrArr[i].Width, sqrArr[i].Height, sqrArr[i].Length);
            cylArr.push_back(C);
        }
    cout << "The cylindrical base rectangular blocks have been read into an array. There are " << cylArr.size() << " of them\n" << endl;

    // Generating an array for the spherical blocks
    vector<SphericalBlocks> sphArr;
    for(int i = 0; i < cubArr.size(); i++){
            SphericalBlocks S(cubArr[i].Width, cubArr[i].Height, cubArr[i].Length);
            sphArr.push_back(S);
        }
    cout << "The spherical blocks have been read into an array. There are " << sphArr.size() << " of them\n" << endl;


    // Sorting the sperical blocks by their diameter 
    cout << "\nSorting the spherical blocks by their diameter: \n" << endl;
    sort(sphArr.begin(), sphArr.end(), [](const SphericalBlocks & block1, const SphericalBlocks & block2)
            {
                return block1.Diameter < block2.Diameter;
     });
    for(SphericalBlocks &block : sphArr)
    cout<< "(D = " << block.Diameter << ", SA = " << block.SphericalSA << ", V = " << block.Volume << ")" << endl;
    cout<< endl;

    // Sorting the cylindrical blocks by their cylindrical surface area
    cout << "\nSorting the cylindrical blocks by their cylindrical surface area: \n" << endl;
    sort(cylArr.begin(), cylArr.end(), [](const CylindricalBlocks & block1, const CylindricalBlocks & block2)
            {
                return block1.CSA< block2.CSA;
     });
    for(CylindricalBlocks &block : cylArr)
    cout<< "(CSA = " << block.CSA<< ", D = " << block.Diameter << ", L = " << block.Length<< ", A = " <<block.Area <<")" << endl;
    cout<< endl;

//cylindrical surface area,
//the diameter of the circular base, the length of the object and the area.
   
} 