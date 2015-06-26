#include "EnemyDoriard.h"
#include "Include.h"

EnemyDoriard::EnemyDoriard(){
	m_image = LoadGraph("Asset/Enemy/Doriard.png");
}


EnemyDoriard::~EnemyDoriard(){
	DeleteGraph(m_image);
}

void EnemyDoriard::Render(){
	DrawExtendGraph(0, 0,
		1280, 720, m_image, FALSE);
}