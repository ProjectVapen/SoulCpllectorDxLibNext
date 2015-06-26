#pragma once
#include "EnemyBase.h"
class EnemyOrthors :
	public EnemyBase
{



	public:
		EnemyOrthors();
		~EnemyOrthors();

		void Render()override;
};

