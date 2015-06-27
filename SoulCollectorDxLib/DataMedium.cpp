#include "DataMedium.h"


DataMedium::DataMedium()
{
	sMedium.m_sName = "NULL";
	sMedium.m_sLv = 0;
	sMedium.m_sHp = 0;
	sMedium.m_sAtk = 0;
	sMedium.m_sDef = 0;
	sMedium.m_sSpd = 0;
	sMedium.m_sSkl = 0;
	sMedium.m_sTag = 0;
}


void DataMedium::m_SetMedium(std::string n, int l, int h, int a, int d, int s, int sk, int t){
	sMedium.m_sName = n;
	sMedium.m_sLv = l;
	sMedium.m_sHp = h;
	sMedium.m_sAtk = a;
	sMedium.m_sDef = d;
	sMedium.m_sSpd = s;
	sMedium.m_sSkl = sk;
	sMedium.m_sTag = t;
}