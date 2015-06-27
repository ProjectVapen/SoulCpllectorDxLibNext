#include "ManagementScene.h"
#include "ManagementTitle.h"
#include "ManagementStart.h"
#include "ManagementBattle.h"
#include "DxLib.h"

ManagementScene::eState ManagementScene::m_stateScene = eState::eInit;
std::shared_ptr<ManagementBase>ManagementScene::m_pCurrentManagement = nullptr;
std::shared_ptr<ManagementBase>ManagementScene::m_pNextManagement	= nullptr;
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
	m_pCurrentManagement = Find(ManagementTitle::m_sceneName);
	m_pFadeIn->Start(Transition::State::BlackIn);
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

// �V�[����؂�ւ���
// ���ɍs���V�[���̓o�^��
void ManagementScene::ChangeScene(const ChangeSceneData& changeData){



	m_pNextManagement = Find(changeData.m_name);


	m_pFadeOut->Start(changeData.m_fadeOutState);
	

	m_changeSceneData = changeData;
	m_stateScene = eState::eFadeOut;

}

void ManagementScene::Init(){
	
	
	if (m_stateScene != eState::eInit)return;

	m_pCurrentManagement->Init();	//����������
	m_pCurrentManagement->Render();	//���ꂼ��̃V�[���̔w�i�`��


	m_stateScene = eState::eUpData;
	
	
}


void ManagementScene::UpDate(){
	
	if (m_stateScene != eState::eUpData)return;
	m_pCurrentManagement->UpDate();

	WaitKey();
	
}




void ManagementScene::FadeOut(){

	if (m_stateScene != eState::eFadeOut)return;
	
	m_pCurrentManagement->Render();
	m_pFadeOut->UpData();

	if (m_pFadeOut->IsEnd())
	{
		
		m_pCurrentManagement = m_pNextManagement;
	
		m_stateScene = eState::eInit;
	}
}


void ManagementScene::Loop(){
	FadeOut();

	Init();

	UpDate();
}

