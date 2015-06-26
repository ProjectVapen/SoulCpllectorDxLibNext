#include "EnemyEvilFlame.h"
#include "Include.h"

EnemyEvilFlame::EnemyEvilFlame(){
	m_image = LoadGraph("Asset/Enemy/EvilFlame.png");
}


EnemyEvilFlame::~EnemyEvilFlame(){
	DeleteGraph(m_image);
}

void EnemyEvilFlame::Render(){
	DrawExtendGraph(0, 0,
		1280, 720, m_image, FALSE);
}