#include "BattleEnemy.h"


BattleEnemy::BattleEnemy():
m_ELEMENTFIRST(0),
m_ELEMENTSECOUND(1),
m_ELEMENTTHIRD(2),
m_ELEMENTFOURTH(3),
m_ELEMENTFIFTH(4){
	
	int vecSize = 0;

	m_pDataEnemy = std::make_unique<DataEnemy>("Asset/CSV/Enemy/EnemyList.csv");

	m_vecEnemy.resize(m_pDataEnemy->GetJoinBattle());
	for (int i = 0; i < m_pDataEnemy->GetJoinBattle(); i++){
		vecSize += 1;

		m_pDataEnemy->RandomPickUpEnemy();
		
		
		
		m_vecEnemy[i].EnemyName(m_pDataEnemy->GetEnemyName());
		m_vecEnemy[i].EnemyID(m_pDataEnemy->GetEnemyID());
		m_vecEnemy[i].EnemyAttribute(m_pDataEnemy->GetEnemyAttribute());
		

		m_vecEnemy[i].EnemyHP(m_pDataEnemy->GetEnemyHP());
		m_vecEnemy[i].EnemyATK(m_pDataEnemy->GetEnemyATK());
		m_vecEnemy[i].EnemyDEF(m_pDataEnemy->GetEnemyDEF());
		m_vecEnemy[i].EnemySPD(m_pDataEnemy->GetEnemySPD());

		m_vecEnemy[i].EnemyImagePath(m_pDataEnemy->GetEnemyImagePath());
		m_vecEnemy[i].EnemyLoadImage();
		
	
	}
	
		
	m_enemyPotion = 0;
	
}


BattleEnemy::~BattleEnemy(){
	
}


void BattleEnemy::Render(){
	
	for (int i = 0; i < m_pDataEnemy->GetJoinBattle(); i++){
		
		
		if (i < 3)
		{
			
			m_vecEnemy[i].Render(250, 10 + (150 * i), 400, 150 + (150 * i));
		}
		else	
		{
			
			m_vecEnemy[i].Render(50, 100 + (150 * m_enemyPotion), 200, 230 + (150 * m_enemyPotion));
			m_enemyPotion += 1;
		}
	}
	
	

}

void BattleEnemy::Proc(){
	//“G‚Ìˆ—
}


void BattleEnemy::VectorRemove(unsigned int element){

	m_vecEnemy.erase(m_vecEnemy.begin() + element);
	
}


bool BattleEnemy::IsDead(unsigned int element){
	if (m_vecEnemy[element].EnemyHP()< 0)
	{
		VectorRemove(element);
		return true;
	}
	return false;
}

bool BattleEnemy::EnemyBrain(){
	//Žvl‚Ìˆ—

	return true;
}

void BattleEnemy::ImageDelete(){
	m_vecEnemy.clear();
}