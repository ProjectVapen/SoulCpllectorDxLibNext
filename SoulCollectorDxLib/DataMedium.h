#pragma once
#include "Include.h"
class DataMedium
{
protected:
	typedef struct _SMedium{
		std::string m_sName;//���O
		int m_sLv;//���x��
		int m_sHp;//�q�b�g�|�C���g
		int m_sAtk;//�U����
		int m_sDef;//�h���
		int m_sSpd;//�f����
		int m_sExp;//�擾�o���l
		int m_sSkl;//�Z�b�g���ꂽ�X�L��
		int m_sTag;//�U���Ώ�
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