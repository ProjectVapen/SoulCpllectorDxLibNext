#pragma once
/*
	
	�Q�[���S�̂̃f�[�^�N���X
	�Q�[�����ɕۑ����Ƃ������̂�ۑ�����

*/
#include "DataCard.h"
#include "DataEnemy.h"
#include "DataMedium.h"
#include "DataPlayer.h"

#include "Include.h"
class AppData{

	private:

		bool m_upData;

		std::string m_saveEnemyListPath;

	public:
		
		AppData();
		~AppData();
		bool AppUpDataFlg();
		void IsUpData(bool upData);

		void EnemyListFilePath(std::string);
		std::string  EnemyListFilePath();

};

