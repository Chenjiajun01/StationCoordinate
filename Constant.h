#ifndef CONSTANT_H
#define  CONSTANT_H
#include <cmath>

const int		TRUETTT =1;
const int		OUTPUTOMC = TRUETTT;
const int		OUTPUTSAT = TRUETTT;
const int		OUTPUTCYC = 1;
const int		OUTPUTLIN = TRUETTT;
//////////////////////////////////////////////////////////////////////////
const double	INTERVAL_SOLID =  900.0;
const double	INTERVAL_WINDUP=  900.0;
const double	INTERVAL_PHASED=  300.0;

const bool	IF_CONAIR = false;
////////////////////截止高度角/////////////////////////////////////////////
const int		ELE_CUT		= 8;
//////////////////////////////////////////////////////////////////////////
const long int DATANUM_A = 100000;
const long int DATANUM_B = 100000;
/////////////////////基本常数/////////////////////////////////////////
const int		NLINE_LENGTH= 82;
const int		OLINE_LENGTH= 82;
const double	GM_EARTH	= 3.986004415e14;	/*地球引力常数*/
const double	GM_SOLAR	= 1.32712440e20;	/*太阳引力常数*/
const double	GM_LUNA		= 4.9027993e12;		/*月球引力常数*/

const double	JSD			= 7.2921151467e-5;	/*自转角速度*/
const double	PI			= 3.1415926535897932384626433832795;	/*圆周率*/							  
const double	LIGHTS		= 299792458;		/*光速(米被定义为1/299,792,458秒内光通过的路程)*/
const double	LIGHTN		= 0.299792458;		//1纳秒光通过的距离	
const double	E_MATH		= 2.7182818;		/*数学中的小e*/
const double    DAY_LENGTH  = 0.99726956634;    /*恒星日长*/
/////////////////////固体潮改正中的h l////////////////////////////////
const double	H_LOVE	= 0.609;				/* h       */
const double	L_LOVE	= 0.0852;				/* l       */	
const double	H2_LOVE = 0.6078;				/* h 二阶项*/
const double	L2_LOVE = 0.0847;				/* l 二阶项*/
const double	H3_LOVE = 0.292;				/* h 三阶项*/
const double	L3_LOVE = 0.015;				/* l 三阶项*/
//////////////////////////////////////////////////////////////////////
//			WGS-84椭球参数
//////////////////////////////////////////////////////////////////////

const double	A_WGS84		= 6378137.00;		/*WGS-84椭球参数a (m)*/
const double	B_WGS84		= 6356752.3142;		/*WGS-84椭球参数b (m)*/
const double	C_WGS84		= 6399593.6258;		/*WGS-84椭球参数c (m)*/
const double	IB_WGS84	= 1/298.257223563;	/*WGS-84椭球参数ib (m)*/
const double	EE_WGS84	= 0.006694379013;	/*WGS-84椭球参数e平方 (m)*/
const double	EEP_WGS84	= 0.00673949674227; /*WGS-84椭球参数ep 平方 (m)*/
//const double	MR_WGS84	= 6371000.78999407;	/*WGS-84椭球平均半径 (m)*/
const double	MR_WGS84	= 6371317.00;	/*WGS-84椭球平均半径 (m)*/
//////////////////////////////////////////////////////////////////////
//			地球基本几何参数
//////////////////////////////////////////////////////////////////////
const double	A			= 6378164.0;		//长半径
const double	B			= 6356779.0;		//短半径
const double	MR			= 6371027.68505982;	//地球平均半径

//////////////////////////////////////////////////////////////////////
//          标准气象历元
//////////////////////////////////////////////////////////////////////
const double	P_BZ		= 1013.25;			//标准大气压(毫巴/百帕)
const double	T_JD		= 273.16;			//绝对温度中的0度?
const double	T_BZ		= T_JD +15;			//海平面的平均温度(度)
const double	E_BZ		= 213;				//海平面的水气压
const double	R_BZ		= 1.29;				//标准大气压下的大气密度 

//////////////////////////////////////////////////////////////////////
//          Niell投影函数常量
//////////////////////////////////////////////////////////////////////
const double	T0_N		= 28;
const double	HT[3]		= {2.53e-5,5.49e-3,1.14e-3};
const double	HTFZ		= 1.00002516201782;

//干分量投影函数插值表 15.30.45.60.75

const double	HYDAVE[5][3]=  {{1.2769934e-3,2.9153695e-3,62.610505e-3},
{1.2683230e-3,2.9152299e-3,62.837393e-3},
{1.2465397e-3,2.9288445e-3,63.721774e-3},
{1.2196049e-3,2.9022565e-3,63.824265e-3},
{1.2045996e-3,2.9024912e-3,64.258455e-3}};
const double	HYDAMP[5][3]=  {{0.0,0.0,0.0},
{1.2709626e-5,2.1414979e-5,9.0128400e-5},
{2.6523662e-5,3.0160779e-5,4.3497037e-5},
{3.4000452e-5,7.2562722e-5,84.795348e-5},
{4.1202191e-5,11.723375e-5,170.37206e-5}};
//湿分量投影函数插值表 15.30.45.60.75
const double	WETAVE[5][3]=  {{5.8021879e-4,1.4275268e-3,4.3472961e-2},
{5.6794847e-4,1.5138625e-3,4.6729510e-2},
{5.8118019e-4,1.4572572e-3,4.3907931e-2},
{5.9727542e-4,1.5007428e-3,4.4626982e-2},
{6.1641693e-4,1.7599082e-3,5.4736039e-2}};

//////////////////////////////////////////////////////////////////////////
//			相对效应
//////////////////////////////////////////////////////////////////////////

//const double	RELATIVE_CONST=-686.423665;		/*相对效应(距离)常数*/		 
const double	RELATIVE_CONST = 2*GM_EARTH/pow(299792458.0,2);
//////////////////////////////////////////////////////////////////////////
//预处理
//////////////////////////////////////////////////////////////////////////
const double	CYCLE_CUT_GF	= 0.02;
const double	CYCLE_CUT_DIST	= 0.06;
//////////////////////////////////////////////////////////////////////
//          载波波长与频率
//////////////////////////////////////////////////////////////////////
const double	FL1			= 1575420000;							//L1的频率（单位：Hz）
const double	NAMEDAL1	= 0.19029367279836488047631742646405;	//L1的波长（单位：m）
const double	FL2			= 1227600000;							//L2的频率
const double	NAMEDAL2	= 0.24421021342456825;					//L2的波长
const double	ION1		= 2.54572778016316;						//(FL1*FL1/(FL1*FL1-FL2*FL2)); 
const double	ION2		= -1.98368398454272;					//(-FL1*FL2/(FL1*FL1-FL2*FL2));
const double	ION3		= -1.545727780163160;					//(-FL2*FL2/(FL1*FL1-FL2*FL2));
const double	ION12		= 1.64694444444444;						//L2的电离层延迟相对于L1的比例
const double	FION		= 1575420000;							//=FL1无电离层折射组合观测值的频率
const double	NAMEDAION	= 0.19029367279836488047631742646405;   //=NAMEDAL1无电离层折射组合观测值的波长 = NAMEDAL1
const double	FWIDE_LANE	= 347820000;							//FL1 - FL2;
const double	NAMEDAWID	= 0.861918400322006;					//LIGHTS/FWIDE_LANE;宽巷组合波长
const double	FNARROW		= 2803020000;							//FL1 + FL2;
const double	NAMEDANARROW= 0.106953378142147;					//LIGHTS/FNARROW;窄巷组合波长
const double	K1			= 40.3033246755749;						//电离层折射率第一项系数
const double	ALFA		= 95188580000988500.0;					//计算TEC时的系数alfa


//////////////////////////////////////////////////////////////////////////
const double	InitialVar	= 1000000000000.0;				//滤波初始方差
const int		DaySecond	= 86400;

/////////////////////////////////////////////////////////////////////////
                                                          //层析常量设置
const double pInterval = 3600.0; //IRI电子密度间隔
//const int ppieceNum = 4; //iri每天只下4个时段的数据
const double Angle_limit = 15.0 * PI / 180.0; //截止高度角低于10°数据剔除
const double factor = pow(FL1 * FL2, 2) /(40.28 * (FL1 * FL1 - FL2 * FL2)) * 1e-16; //计算STEC时Psm乘以的系数


#endif