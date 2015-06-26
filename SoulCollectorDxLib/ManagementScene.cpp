#include "ManagementScene.h"
#include "ManagementTitle.h"
#include "ManagementStart.h"
#include "ManagementBattle.h"
#include "DxLib.h"

ManagementScene::eState ManagementScene::m_stateScene = eState::eInit;
std::shared_ptr<ManagementBase>ManagementScene::m_pCurrentScene = nullptr;
std::shared_ptr<ManagementBase>ManagementScene::m_pNextScene	= nullptr;
std::unordered_map<std::string, std::shared_ptr<ManagementBase>>ManagementScene::m_pSceneData;


ManagementScene::ManagementScene() :
m_pFadeIn(std::make_unique<Transition>()),
m_pFadeOut(std::make_unique<Transition>()),
m_changeSceneData(){

	/*	�R���X�g���N�^�ŃQ�[�����̃V�[����o�^	*/
	Register(std::make_shared<ManagementTitle>(*this));
	Register(std::make_shared<ManagementStart>(*this));
	Register(std::make_shared<ManagementBattle>(*this));

	/*	�ŏ��̓^�C�g����ʂ���X�^�[�g	*/
	m_pCurrentScene = Find(ManagementTitle::m_sceneName);

}


ManagementScene::~ManagementScene(){

}

/*	�V�[���̓o�^����	*/
void ManagementScene::Register(std::shared_ptr<ManagementBase> scene){

	//�����ŘA�z�z��ɃL�[�Ɨv�f�����Ă�i�������F�L�[/�������F�v�f�j
	m_pSceneData.insert(std::make_pair(scene->Name(), scene));
}


/*	�V�[�����̍폜	*/
void ManagementScene::Delete(const std::string& name){



	auto findScene = m_pSceneData.find(name);
	if (findScene == m_pSceneData.end())return;

	m_pSceneData.erase(findScene);

}


/*	�V�[�������������Ď擾	*/
std::shared_ptr<ManagementBase> ManagementScene::Find(const std::string& name){



	auto findScene = m_pSceneData.find(name);
	if (findScene == m_pSceneData.end())return nullptr;

	return findScene->second;
}

void ManagementScene::ChangeScene(const ChangeSceneData& changeData){

	m_pNextScene = Find(changeData.m_sName);

	m_changeSceneData = changeData;

}

void ManagementScene::Init(){
	if (m_stateScene != eState::eInit)return;

	m_pCurrentScene->Init();


	m_stateScene = eState::eUpData;
}

//���������ۂ̃��C��
void ManagementScene::UpDate(){
	Init();

	if (m_stateScene!= eState::eUpData)return;

	m_pCurrentScene->Render();
	m_pCurrentScene->UpDate();
	

	WaitKey();
	
	m_stateScene = eState::ePrevDelete;
	PrevDelete();
	m_pCurrentScene = m_pNextScene;
	m_stateScene = eState::eInit;
}

void ManagementScene::PrevDelete(){
	if (m_stateScene != eState::ePrevDelete)return;
	m_pCurrentScene->ImageDelete();

	m_stateScene = eState::eInit;
	
}