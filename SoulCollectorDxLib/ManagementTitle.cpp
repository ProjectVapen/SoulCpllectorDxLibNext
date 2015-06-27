#include "ManagementTitle.h"
#include "ManagementStart.h"
#include "SceneTitle.h"
#include "Application.h"

const std::string ManagementTitle::m_sceneName = "Title";

ManagementTitle::ManagementTitle(ManagementScene& managementScene) :
ManagementBase(m_sceneName, managementScene)
{
	
}


ManagementTitle::~ManagementTitle()
{
	m_pScnene->ImageDelete();
}


void ManagementTitle::PushKeyState(AppController::eGetController pushKey){
	//コントローラー入力処理を記述
}

void ManagementTitle::PushKeyState(){

}

void ManagementTitle::Init(){

	DrawFormatString(0, 10, GetColor(255, 255, 255), "タイトル画面");
	m_pScnene = std::make_unique<SceneTitle>();
}

bool ManagementTitle::Render(){
	m_pScnene->Render();
	return true;
}

void ManagementTitle::UpDate(){

	
	ChangeScene(ManagementScene::ChangeSceneData(
		ManagementStart::m_sceneName, Transition::State::BlackIn, Transition::State::BlackOut));
		
}

void ManagementTitle::ImageDelete(){

	m_pScnene = nullptr;
}

