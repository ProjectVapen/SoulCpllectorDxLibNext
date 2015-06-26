#include "EnemyBigShield.h"
#include "Include.h"

EnemyBigShield::EnemyBigShield(){

	m_image = LoadGraph("Asset/Enemy/BigShield.png");
	
}


EnemyBigShield::~EnemyBigShield(){
	DeleteGraph(m_image);
}

void EnemyBigShield::Render(){
	DrawExtendGraph(0, 0,
		1280, 720, m_image, FALSE);
}