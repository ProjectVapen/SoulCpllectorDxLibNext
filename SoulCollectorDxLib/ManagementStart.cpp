#include "ManagementStart.h"
#include "ManagementTitle.h"
#include "ManagementBattle.h"

#include "SceneStart.h"

#include "Application.h"

const std::string ManagementStart::m_sceneName = "Start";

ManagementStart::ManagementStart(ManagementScene& managementScene) :
ManagementBase(m_sceneName, managementScene)
{
	
}


ManagementStart::~ManagementStart()
{
	
}

void ManagementStart::PushKeyState(AppController::eGetController pushKey){
	//コントローラー入力処理を記述
	
}

void ManagementStart::PushKeyState(){

//	pApp->m_pAppData->IsUpData(true);
}

void ManagementStart::Init(){
	//スタート画面の初期化処理
	DrawFormatString(0, 10, GetColor(255, 255, 255), "スタート画面");
	m_pScnene = std::make_unique<SceneStart>();
}

bool ManagementStart::Render(){
	m_pScnene->Render();
	return true;
}

void ManagementStart::UpDate(){
	//切り替えなどの更新処理
	ChangeScene(ManagementScene::ChangeSceneData(
		ManagementBattle::m_sceneName));
}

void ManagementStart::ImageDelete(){

	m_pScnene->ImageDelete();
	m_pScnene = nullptr;
}


