#pragma once
/*
	ゲームの全体の管理クラス



*/
#include "ManagementBattle.h"
#include "ManagementScene.h"
#include "ManagementTitle.h"
#include "ManagementStart.h"
#include "Include.h"

class AppManager
{
	private:
		

	public:
		AppManager();
		~AppManager();

		std::unique_ptr<ManagementScene>  m_pManagScene;

		void AppUpData();	//	シーンを切り替えるとかなんかしらあった時の更新処理


};

