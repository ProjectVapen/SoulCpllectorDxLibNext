/*	CSVfile読み込みじに使用	*/
#include <fstream>
#include <sstream>
/*	ランダム値生成に使用	*/
#include <time.h>
#include <math.h>
#include <iostream>

#include "Enemy.h"
#include "DataEnemy.h"

#include "Application.h"
extern std::unique_ptr<Application> pApp;

DataEnemy::DataEnemy():
m_MAX_JOIN_ENEMYS(5),
m_ALL_ENEMYS(10){

}

DataEnemy::DataEnemy(std::string filePath) :
m_MAX_JOIN_ENEMYS(5),
m_ALL_ENEMYS(10){

	srand((unsigned int)time(NULL));

	m_joinBattleEnemys = 0;
	m_pushNumber = 0;

	RandomJoinBattle();

		if (ReadCsvData(filePath))
		{

		}	
	
}


DataEnemy::~DataEnemy()
{
}





bool DataEnemy::ReadCsvData(std::string filePath){

	

	std::ifstream file;
	std::vector<std::string>data;

	file.open(filePath);
	if (!file)
	{
		MessageBox(NULL, "ファイルが読み込まれていません", "エラー", MB_OK);
		std::cerr << "Can't Read Enemy's CSVfile" << std::endl;
	}

	std::string csvLine;
	std::string csvCol;

	m_enemyAllData.clear();
	m_elementEnemyCnt = 0;
	m_loadCnt = 0;
	int cnt = 0;
	while (std::getline(file, csvLine))
	{
		std::stringstream csvStream(csvLine);
		m_loadCnt += 1;
		while (getline(csvStream, csvCol, ','))
		{
			data.push_back(csvCol);

		}

		m_enemyAllData.resize(m_loadCnt);
		m_enemyAllData[m_elementEnemyCnt].m_sName = data[0];
		m_enemyAllData[m_elementEnemyCnt].m_sID = std::atoi(data[1].c_str());
		m_enemyAllData[m_elementEnemyCnt].m_sAttribute = std::atoi(data[2].c_str());

		m_enemyAllData[m_elementEnemyCnt].m_sHP=std::atoi(data[3].c_str());
		m_enemyAllData[m_elementEnemyCnt].m_sATK = std::atoi(data[4].c_str());
		m_enemyAllData[m_elementEnemyCnt].m_sDEF = std::atoi(data[5].c_str());
		m_enemyAllData[m_elementEnemyCnt].m_sSPD = std::atoi(data[6].c_str());
		m_enemyAllData[m_elementEnemyCnt].m_sImagePath = data[7];
		
		++m_elementEnemyCnt;
		
		data.clear();
	}

	file.close();
	return true;
}


void DataEnemy::RandomJoinBattle(){
	unsigned int Value = 0;


	Value = rand() % m_MAX_JOIN_ENEMYS + 1;

	m_joinBattleEnemys = Value;

}

void DataEnemy::RandomPickUpEnemy(){
	m_pushNumber = 0;


	m_pushNumber = rand() % m_ALL_ENEMYS;
}

int DataEnemy::GetJoinBattle()const{
	return m_joinBattleEnemys;
}

std::string DataEnemy::GetEnemyName(){

	return m_enemyAllData[m_pushNumber].m_sName;
}
int DataEnemy::GetEnemyID(){

	return m_enemyAllData[m_pushNumber].m_sID;
}
int DataEnemy::GetEnemyAttribute(){

	return m_enemyAllData[m_pushNumber].m_sAttribute;
}

int DataEnemy::GetEnemyHP(){
	return m_enemyAllData[m_pushNumber].m_sHP;
}
int DataEnemy::GetEnemyATK(){

	return m_enemyAllData[m_pushNumber].m_sATK;
}
int DataEnemy::GetEnemyDEF(){

	return m_enemyAllData[m_pushNumber].m_sDEF;
}
int DataEnemy::GetEnemySPD(){

	return m_enemyAllData[m_pushNumber].m_sSPD;
}

std::string DataEnemy::GetEnemyImagePath()const{

	return m_enemyAllData[m_pushNumber].m_sImagePath;
}