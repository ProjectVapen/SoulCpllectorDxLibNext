#pragma once
/*
	
	ゲーム全体のデータクラス
	ゲーム中に保存しときたいのを保存する

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

