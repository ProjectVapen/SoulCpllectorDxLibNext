#pragma once
#include "Include.h"
#include "Enemy.h"

class DataEnemy
{

	private:
			
		
		
		typedef struct _SEnemyData{
			std::string m_sName;
			int m_sID;
			int m_sAttribute;
			int m_sHP;
			int m_sATK;
			int m_sDEF;
			int m_sSPD;
			std::string m_sImagePath;
		}sEnemyData; 
		

		std::vector<sEnemyData>m_enemyAllData;

		std::string m_filePath;

		/*	ファイルからvector配列に移す際に使用	*/
		int m_elementEnemyCnt;		
		int m_loadCnt;

		int m_joinBattleEnemys;	//戦闘に出てくる敵の数（ランダム値）
		int m_pushNumber;		//何が出てくるか（ランダム値）

		int const m_MAX_JOIN_ENEMYS; //	戦闘に出てくる最大数
		int const m_ALL_ENEMYS;		//そこに出てくる種類の上限

	public:
		DataEnemy();

		DataEnemy(std::string filePath);
		~DataEnemy();

		bool ReadCsvData(std::string filePath);

		int GetJoinBattle()const;
		void RandomJoinBattle();
		void RandomPickUpEnemy();

		//std::unique_ptr<Enemy> SetEnemy();
		std::string GetEnemyName();
		int GetEnemyID();
		int GetEnemyAttribute();

		int GetEnemyHP();
		int GetEnemyATK();
		int GetEnemyDEF();
		int GetEnemySPD();
		
		std::string GetEnemyImagePath()const;
		
};

