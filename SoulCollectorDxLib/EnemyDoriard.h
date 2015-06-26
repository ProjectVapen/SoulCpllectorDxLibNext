#pragma once
#include "EnemyBase.h"

class EnemyDoriard :
	public EnemyBase
{

	public:
		EnemyDoriard();
		~EnemyDoriard();

		void Render()override;
};

