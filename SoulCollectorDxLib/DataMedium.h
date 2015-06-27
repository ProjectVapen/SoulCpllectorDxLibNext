#pragma once
#include "Include.h"
class DataMedium
{
protected:
	typedef struct _SMedium{
		std::string m_sName;//名前
		int m_sLv;//レベル
		int m_sHp;//ヒットポイント
		int m_sAtk;//攻撃力
		int m_sDef;//防御力
		int m_sSpd;//素早さ
		int m_sExp;//取得経験値
		int m_sSkl;//セットされたスキル
		int m_sTag;//攻撃対象
	};
public:
	DataMedium();
	~DataMedium(){}
	_SMedium sMedium;
	void m_SetMedium(std::string n, int l, int h, int a, int d, int s, int sk, int t);

	std::string m_MediumName(std::string n){ sMedium.m_sName = n; }
	void m_MediumLv(int l){ sMedium.m_sLv = l; }
	void m_MediumHp(int h){ sMedium.m_sHp = h; }
	void m_MediumAtk(int a){ sMedium.m_sAtk = a; }
	void m_MediumDef(int d){ sMedium.m_sDef = d; }
	void m_MediumSpd(int s){ sMedium.m_sSpd = s; }
	void m_MediumExp(int e){ sMedium.m_sExp = e; }
	void m_MediumSkl(int sk){ sMedium.m_sSkl = sk; }
	void m_MediumTag(int t){ sMedium.m_sTag = t; }

	std::string m_MediumName(){ return sMedium.m_sName; }
	int m_MediumLv(){ return sMedium.m_sLv; }
	int m_MediumHp(){ return sMedium.m_sHp; }
	int m_MediumAtk(){ return sMedium.m_sAtk; }
	int m_MediumDef(){ return sMedium.m_sDef; }
	int m_MediumSpd(){ return sMedium.m_sSpd; }
	int m_MediumExp(){ return sMedium.m_sExp; }
	int m_MediumSkl(){ return sMedium.m_sSkl; }
	int m_MediumTag(){ return sMedium.m_sTag; }
};

class Meduko : public DataMedium{
public:
	Meduko(){}
	~Meduko(){}
};

class Ozaki : public DataMedium{
public:
	Ozaki(){}
	~Ozaki(){}
};

class Ayataka : public DataMedium{
public:
	Ayataka(){}
	~Ayataka(){}
};