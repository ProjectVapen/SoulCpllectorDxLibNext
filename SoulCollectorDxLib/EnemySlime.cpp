#include "EnemySlime.h"
#include "Include.h"

EnemySlime::EnemySlime(){
	m_image = LoadGraph("Asset/Enemy/Slime.png");
}


EnemySlime::~EnemySlime(){
	DeleteGraph(m_image);
}

void EnemySlime::Render(){
	DrawExtendGraph(0, 0,
		1280, 720, m_image, FALSE);
}