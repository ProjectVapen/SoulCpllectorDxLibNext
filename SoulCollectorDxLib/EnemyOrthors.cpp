#include "EnemyOrthors.h"
#include "Include.h"

EnemyOrthors::EnemyOrthors(){
	m_image = LoadGraph("Asset/Enemy/Orthros.png");
}


EnemyOrthors::~EnemyOrthors(){
	DeleteGraph(m_image);
}

void EnemyOrthors::Render(){
	DrawExtendGraph(0, 0,
		1280, 720, m_image, FALSE);
}