#pragma once
#include "EnemyBase.h"
class EnemyGoblinWarrior :
	public EnemyBase
{

	public:
		EnemyGoblinWarrior();
		~EnemyGoblinWarrior();

		void Render()override;
};

