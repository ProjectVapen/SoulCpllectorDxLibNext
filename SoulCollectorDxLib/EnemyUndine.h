#pragma once
#include "EnemyBase.h"
class EnemyUndine :
	public EnemyBase
{

	private:


	public:
		EnemyUndine();
		~EnemyUndine();
	
		void Render()override;
};
