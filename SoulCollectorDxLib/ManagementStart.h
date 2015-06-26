#pragma once
/*
	ManagementStart

	スタート画面管理クラス
*/
#include "AppController.h"
#include "ManagementBase.h"
class ManagementStart:public ManagementBase
{
	public:
		ManagementStart(ManagementScene& managementScene);
		~ManagementStart();

		void PushKeyState(AppController::eGetController pushKey);
		void PushKeyState();

		void Init()override;
		void UpDate()override;
		bool Render()override;
		void ImageDelete()override;

		static const std::string m_sceneName;
};

