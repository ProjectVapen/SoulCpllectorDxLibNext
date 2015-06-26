#pragma once
#include "EnemyBase.h"
class EnemyEvilFlame :
	public EnemyBase
{
	public:
		EnemyEvilFlame();
		~EnemyEvilFlame();

		void Render()override;
};

