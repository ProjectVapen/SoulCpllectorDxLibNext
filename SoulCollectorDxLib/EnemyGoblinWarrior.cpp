#include "EnemyGoblinWarrior.h"
#include "Include.h"

EnemyGoblinWarrior::EnemyGoblinWarrior(){
	m_image = LoadGraph("Asset/Enemy/GoblinWarrier.png");
}


EnemyGoblinWarrior::~EnemyGoblinWarrior(){
	DeleteGraph(m_image);
}

void EnemyGoblinWarrior::Render(){
	DrawExtendGraph(0, 0,
		1280, 720, m_image, FALSE);
}