#pragma once
#include "Include.h"
class Enemy
{
	
	private:
		std::string m_name;
		int m_id;
		int m_attribute;
		int m_hp;
		int m_atk;
		int m_def;
		int m_spd;

		std::string m_enemyImagePath;
		int m_enemyImage;

	public:
		Enemy();
		~Enemy();
		void Render(int x, int y, int width, int height);

		//セッター
		void EnemyName(std::string);
		void EnemyID(int);
		void EnemyAttribute(int);
		
		void EnemyHP(int);;
		void EnemyATK(int);
		void EnemyDEF(int);
		void EnemySPD(int);
		
		void EnemyImagePath(std::string);
		void EnemyLoadImage();

		//ゲッター
		std::string EnemyName();
		int EnemyID();
		int EnemyAttribute();
		
		int EnemyHP();;
		int EnemyATK();
		int EnemyDEF();
		int EnemySPD();
		
		std::string EnemyImagePath();
};

