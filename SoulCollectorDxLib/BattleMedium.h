#pragma once
#include "Include.h"
#include "DataMedium.h"
class BattleMedium
{
#define m_MEDIUM1 1
#define m_MEDIUM2 2
#define m_MEDIUM3 3

	Meduko Medium1;
	Ozaki  Medium2;
	Ayataka Medium3;

	int m_target;
public:
	BattleMedium();
	~BattleMedium(){}
	void m_DataInit();//�L�����̏�����
	void m_Skill();//�X�L���擾
	void m_Target();//�G����
	void m_Proc();//�S�̏���
};

