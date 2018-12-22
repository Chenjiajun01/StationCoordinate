//
//  main.cpp
//  StationCoordinate
//
//  Created by Jiajun Chen on 05/10/2018.
//  Copyright © 2018 Jiajun Chen. All rights reserved.
//

#include <iostream>
#include "Rinex.h"
using namespace std;

int main(int argc, const char * argv[]) {
    if(argc<3)  //parameter
    {
        cout<<"Usage: StationCoordiate <ofile> <outfile>" << endl;
        cout<<"       ofile: " << endl;
        cout<<"       outfile: " << endl;
        return 0;
    }
    string ofileName = argv[1];
    string outfileName = argv[2];
    
    CObsFile ofile;
    ofile.m_path = ofileName;
    if (false == ofile.ReadObsFile()) {
        return 0;
    }
    
    //get site name
    size_t baseNamepos = ofileName.rfind(".") - 8;
    string baseName = ofileName.substr(baseNamepos);
    //cout << "baseName: " << baseName << endl;
    string stationName = baseName.substr(0,4);
    CoorGeo stationCoorgeo;
    stationCoorgeo = ofile.m_Ohead.Appposition;
    
    if (false == WriteStationPosition(outfileName, stationName, stationCoorgeo)){
        cout << "Fail at writing to file" << endl;
        return 0;
    }
    return 0;
}
