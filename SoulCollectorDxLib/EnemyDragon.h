#pragma once
#include "EnemyBase.h"
class EnemyDragon :
	public EnemyBase
{
	public:
		EnemyDragon();
		~EnemyDragon();

		void Render()override;
};

