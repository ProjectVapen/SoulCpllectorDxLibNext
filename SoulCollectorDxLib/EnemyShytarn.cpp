#include "EnemyShytarn.h"
#include "Include.h"

EnemyShytarn::EnemyShytarn(){
	m_image = LoadGraph("Asset/Enemy/Shytarn.png");
}


EnemyShytarn::~EnemyShytarn(){
	DeleteGraph(m_image);
}

void EnemyShytarn::Render(){
	DrawExtendGraph(0, 0,
		1280, 720, m_image, FALSE);
}