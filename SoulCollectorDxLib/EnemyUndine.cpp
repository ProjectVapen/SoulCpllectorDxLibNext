#include "EnemyUndine.h"
#include "Include.h"

EnemyUndine::EnemyUndine(){
	m_image = LoadGraph("Asset/Enemy/Undine.png");
}


EnemyUndine::~EnemyUndine(){
	DeleteGraph(m_image);
}

void EnemyUndine::Render(){
	DrawExtendGraph(0, 0,
		1280, 720, m_image, FALSE);
}