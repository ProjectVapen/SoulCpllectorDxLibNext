#include "Enemy.h"

Enemy::Enemy(){
	std::string m_name = "NULL";
	int m_id		= NULL;
	int m_attribute = NULL;

	int m_hp		= NULL;
	int m_atk		= NULL;
	int m_def		= NULL;
	int m_spd		= NULL;

	std::string m_enemyImagePath = "NULL";
}

Enemy::~Enemy(){

	DeleteGraph(m_enemyImage);
}



void Enemy::Render(int x, int y, int width, int height){
	DrawExtendGraph(x, y,
		width, height, m_enemyImage, FALSE);
}

///////////////////////////////////////
//
//////////////////////////////////////

void Enemy::EnemyName(std::string name){
	m_name = name;
}
void Enemy::EnemyID(int id){
	m_id = id;
}
void Enemy::EnemyAttribute(int attribute){
	m_attribute = attribute;
}


void Enemy::EnemyHP(int hp){
	m_hp = hp;
}
void Enemy::EnemyATK(int atk){
	m_atk = atk;
}
void Enemy::EnemyDEF(int def){
	m_def = def;
}
void Enemy::EnemySPD(int spd){
	m_spd = spd;
}


void Enemy::EnemyImagePath(std::string ImagePath){
	m_enemyImagePath = ImagePath;
	
}

void Enemy::EnemyLoadImage(){
	m_enemyImage = LoadGraph(m_enemyImagePath.c_str());
}

////////////////////////////////////
//
/////////////////////////////////////
std::string Enemy::EnemyName(){
	return this->m_name;
}
int Enemy::EnemyID(){
	return this->m_id;
}
int Enemy::EnemyAttribute(){
	return this->m_attribute;
}


int Enemy::EnemyHP(){
	return this->m_hp;
}
int Enemy::EnemyATK(){
	return this->m_atk;
}
int Enemy::EnemyDEF(){
	return this->m_def;
}
int Enemy::EnemySPD(){
	return this->m_spd;
}


std::string Enemy::EnemyImagePath(){
	return this->m_enemyImagePath;
}