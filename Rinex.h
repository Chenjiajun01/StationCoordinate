#ifndef OBSFILE_H
#define OBSFILE_H

#include <vector>
#include <string>
#include <istream>
#include <fstream>

#include "Coordinate.h"
using namespace std;

//GPS o文件头
class ODataHead
{
public:
	double						RinexVersion;				// RINEX VERSION
	string						GnssType;					// 卫星系统(G或空-GPS，R-GLONASS，M-G+R)
	string						RecType;					// REC TYPE
	string						AntType;					// ANT TYPE
	CoorCar						Appposition;				// APPROX POSITION (XYZ)    
//	CoorCar						Antenna_Delta;				// antenna delta
	double						Interval;					// interval
	short						ObstypeNum;					// observation types number
	vector<string>				Obstype;					// observation types name
//	TimeCalendar				FirstEpoch;					// first epoch
//	TimeCalendar				LastEpoch;					// end epoch
};


//单文件数据处理
class CObsFile
{
public:
	CObsFile();
	~CObsFile();
	
public:
	string m_path; //O file path
	ODataHead m_Ohead; //header
	string m_stname; //station name
    CoorGeo GeoPosition; // position geocode coordinate (BLH)
	
	bool ReadObsFile(); //
};


//////////////////////////////////////////////////全局函数

bool WriteStationPosition(string& filename, string& stationName, CoorGeo& pos);

//bool ReadOfile(string filename, CObsFile& ofile);

#endif 
