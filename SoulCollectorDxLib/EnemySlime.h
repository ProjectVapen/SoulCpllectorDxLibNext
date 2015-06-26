#pragma once
#include "EnemyBase.h"
class EnemySlime :
	public EnemyBase
{


	public:
		EnemySlime();
		~EnemySlime();

		void Render()override;
};

