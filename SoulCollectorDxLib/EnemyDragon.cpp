#include "EnemyDragon.h"
#include "Include.h"

EnemyDragon::EnemyDragon(){
	m_image = LoadGraph("Asset/Enemy/Dragon.png");
}


EnemyDragon::~EnemyDragon(){
	DeleteGraph(m_image);
}

void EnemyDragon::Render(){
	DrawExtendGraph(0, 0,
		1280, 720, m_image, TRUE);
}
