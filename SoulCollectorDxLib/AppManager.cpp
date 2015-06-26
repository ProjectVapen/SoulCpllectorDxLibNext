#include "AppManager.h"
#include "FrameRate.h"


AppManager::AppManager()
{
	m_pManagScene	= std::make_unique<ManagementScene>();
}


AppManager::~AppManager(){
}

void AppManager::AppUpData(){

	m_pManagScene->UpDate();
}
