#include "Rinex.h"
#include "Constant.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <iomanip>

using namespace std;

CObsFile::CObsFile()
{
//	ObsFileNum = 0;
//	m_area = new double[4];
//	EptempNum = 0;
}


CObsFile::~CObsFile()
{
//	delete [] m_area;
}



// 读取单个O文件
bool CObsFile::ReadObsFile()
{
	ifstream infile;
	infile.open(m_path.c_str());
	if (!infile.is_open())
	{
        cout<<"Fail to open file: "<<m_path<<endl;
		return false;
	} 
 	string Line;

	///////////////////////////////////////////////////Read head
	while (getline(infile,Line))
	{		
		if (Line.find("END OF HEADER") != string::npos)
		{
			break;
		}
		if (Line.find("RINEX VERSION / TYPE") != string::npos)
		{
			m_Ohead.RinexVersion = atof(Line.substr(5,4).c_str());
			m_Ohead.GnssType = Line.substr(40,10);
			continue;
		}
		if (Line.find("REC # / TYPE / VERS") != string::npos)
		{
			m_Ohead.RecType = Line.substr(20,11);
			continue;
		}
		if (Line.find("ANT # / TYPE") != string::npos)
		{
			m_Ohead.AntType = Line.substr(20,20);
			continue;
		}
		if (Line.find("APPROX POSITION XYZ") != string::npos)
		{
			m_Ohead.Appposition.X = atof(Line.substr(1,13).c_str());
			m_Ohead.Appposition.Y = atof(Line.substr(15,13).c_str());
			m_Ohead.Appposition.Z = atof(Line.substr(29,13).c_str());

			//判断是否在反演范围
			GeoPosition = co_convCarToGeo(m_Ohead.Appposition); //转换到大地坐标
            /*
			if (false == GThan(m_area[0],stpst.B,m_area[1]) || false == GThan(m_area[2],stpst.L,m_area[3])) //不在范围内放弃读文件
			{
				return false;
			}
             */
			//m_Ohead.Appposition.SetX(atof(Line.substr(1,13).c_str()));
			//m_Ohead.Appposition.SetY(atof(Line.substr(15,13).c_str()));
			//m_Ohead.Appposition.SetZ(atof(Line.substr(29,13).c_str()));
			break;
		}
		if (Line.find("INTERVAL") != string::npos)
		{
			m_Ohead.Interval = atof(Line.substr(4,7).c_str());
			continue;
		}
		if (Line.find("# / TYPES OF OBSERV") != string::npos)
		{
			continue;
		}
		if (Line.find("TIME OF FIRST OBS") != string::npos)
		{
			continue;
		}
	}
	///////////////////////////////////////////////////头文件读取结束
	infile.close();
	cout << "Read " <<m_path<<" finished!"<<endl;
	return true;
}

//
bool WriteStationPosition(string& filename, string& stationName, CoorGeo& position){
    ofstream outfile(filename,ios::out | ios::app);
    if (!outfile.is_open())
    {
        cout << "Fail to open file: " << filename << endl;
        return false;
    }
    
    //outfile.setf(ios_base::adjustfield,ios_base::left);
    outfile.setf(ios_base::fixed,ios_base::floatfield);
    outfile<<setw(5)<< stationName << setw(10)<<setprecision(4) << RadtoAngle(position.B)
                                   << setw(10)<<setprecision(4) << RadtoAngle(position.L)
                                   << setw(10)<<setprecision(4) << position.H << endl;
    outfile.close();
    
    return true;
}
