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
	//�R���g���[���[���͏������L�q
	
}

void ManagementStart::PushKeyState(){

//	pApp->m_pAppData->IsUpData(true);
}

void ManagementStart::Init(){
	//�X�^�[�g��ʂ̏���������
	DrawFormatString(0, 10, GetColor(255, 255, 255), "�X�^�[�g���");
	m_pScnene = std::make_unique<SceneStart>();
}

bool ManagementStart::Render(){
	m_pScnene->Render();
	return true;
}

void ManagementStart::UpDate(){
	//�؂�ւ��Ȃǂ̍X�V����
	ChangeScene(ManagementScene::ChangeSceneData(
		ManagementBattle::m_sceneName));
}

void ManagementStart::ImageDelete(){

	m_pScnene->ImageDelete();
	m_pScnene = nullptr;
}


