#pragma once
#include "Include.h"
#include "Enemy.h"
#include "DataEnemy.h"


class BattleEnemy{

	private:
		
		int const m_ELEMENTFIRST, m_ELEMENTSECOUND, m_ELEMENTTHIRD;
		int const m_ELEMENTFOURTH, m_ELEMENTFIFTH;

		int m_enemyPotion;

		

		std::unique_ptr<DataEnemy> m_pDataEnemy;

	public:
		BattleEnemy();
		~BattleEnemy();
		
		std::vector<Enemy>m_vecEnemy;

		void Render();
		void Proc();
		
		bool EnemyBrain();


		void VectorRemove( unsigned int element);		//vector�R���e�i�̗v�f���폜
		

		bool IsDead(unsigned int element);		//�G�̎���ł邩�����Ă邩�̔��� ��:true/��:false

		void ImageDelete();
};

