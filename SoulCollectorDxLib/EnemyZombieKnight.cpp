#include "EnemyZombieKnight.h"
#include "Include.h"

EnemyZombieKnight::EnemyZombieKnight(){
	m_image = LoadGraph("Asset/Enemy/ZombieKnight.png");
}


EnemyZombieKnight::~EnemyZombieKnight(){
	DeleteGraph(m_image);
}

void EnemyZombieKnight::Render(){
	DrawExtendGraph(0, 0,
		1280, 720, m_image, FALSE);
}