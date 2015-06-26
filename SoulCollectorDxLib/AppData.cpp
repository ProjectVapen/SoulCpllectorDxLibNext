#include "AppData.h"


AppData::AppData()
{
	m_upData = true;
	m_saveEnemyListPath = "NULL";
}


AppData::~AppData()
{
}


bool AppData::AppUpDataFlg(){
	return m_upData;
}

void AppData::IsUpData(bool upData){
	m_upData = upData;
}

void AppData::EnemyListFilePath(std::string enemyFilePath){
	m_saveEnemyListPath = enemyFilePath;
}
std::string  AppData::EnemyListFilePath(){
	return this->m_saveEnemyListPath;
}