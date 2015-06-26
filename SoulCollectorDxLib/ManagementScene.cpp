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

	/*	コンストラクタでゲーム内のシーンを登録	*/
	Register(std::make_shared<ManagementTitle>(*this));
	Register(std::make_shared<ManagementStart>(*this));
	Register(std::make_shared<ManagementBattle>(*this));

	/*	最初はタイトル画面からスタート	*/
	m_pCurrentManagement = Find(ManagementTitle::m_sceneName);

}


ManagementScene::~ManagementScene(){

}

/*	シーンの登録処理	*/
void ManagementScene::Register(std::shared_ptr<ManagementBase> scene){

	//ここで連想配列にキーと要素を入れてる（第一引数：キー/第二引数：要素）
	m_pSceneData.insert(std::make_pair(scene->Name(), scene));
}


/*	シーン情報の削除	*/
void ManagementScene::Delete(const std::string& name){



	auto findScene = m_pSceneData.find(name);
	if (findScene == m_pSceneData.end())return;

	m_pSceneData.erase(findScene);

}


/*	シーン情報を検索して取得	*/
std::shared_ptr<ManagementBase> ManagementScene::Find(const std::string& name){



	auto findScene = m_pSceneData.find(name);
	if (findScene == m_pSceneData.end())return nullptr;

	return findScene->second;
}

void ManagementScene::ChangeScene(const ChangeSceneData& changeData){

	m_pNextManagement = Find(changeData.m_name);

	m_pFadeIn->Start(changeData.m_fadeInState);
	

	m_changeSceneData = changeData;
	m_stateScene = eState::eInit;

}

void ManagementScene::Init(){
	if (m_stateScene != eState::eInit)return;

	m_pCurrentManagement->Init();
	m_pCurrentManagement->Render();

	m_pFadeOut->Start(m_changeSceneData.m_fadeOutState);
	
	
	m_stateScene = eState::eUpData;
}

//ここが実際のメイン
void ManagementScene::UpDate(){
	Init();


	if (m_stateScene != eState::eUpData)return;

	/*	フェードイン・アウト処理*/
	m_pFadeIn->UpData();
	m_pFadeOut->UpData();

	m_pCurrentManagement->UpDate();

	WaitKey();

	if (m_pFadeOut->IsEnd())
	{
		MessageBox(NULL, "NextScene！", "デバッグ", MB_OK);
		m_stateScene = eState::ePrevDelete;
		PrevDelete();

		m_pCurrentManagement = m_pNextManagement;
		m_stateScene = eState::eInit;
	}
}

void ManagementScene::PrevDelete(){
	if (m_stateScene != eState::ePrevDelete)return;
	m_pCurrentManagement->ImageDelete();

}

