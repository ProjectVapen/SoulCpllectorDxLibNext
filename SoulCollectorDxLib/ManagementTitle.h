#pragma once
#include "AppController.h"
#include "ManagementBase.h"
class ManagementTitle : public ManagementBase
{
	public:
		ManagementTitle(ManagementScene& managementScene);
		~ManagementTitle();

		void PushKeyState(AppController::eGetController);
		void PushKeyState();

		void Init()override;
		void UpDate()override;
		bool Render()override;
		void ImageDelete()override;

		static const std::string m_sceneName;
};

