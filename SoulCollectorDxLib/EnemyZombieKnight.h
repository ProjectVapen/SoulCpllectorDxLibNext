#pragma once
#include "EnemyBase.h"
class EnemyZombieKnight :
	public EnemyBase
{
	private:
	
	public:
		EnemyZombieKnight();
		~EnemyZombieKnight();

		void Render()override;

};

