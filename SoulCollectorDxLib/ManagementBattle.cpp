#include "ManagementBattle.h"
#include "ManagementTitle.h"
#include "ManagementStart.h"
#include "SceneBattle.h"
#include "Application.h"


const std::string ManagementBattle::m_sceneName = "Battle";

ManagementBattle::eBattleState ManagementBattle::m_stateBattle = eBattleState::eDrawPhase;
ManagementBattle::eSelect ManagementBattle::m_stateSelect = eSelect::eCardPhase;


ManagementBattle::ManagementBattle(ManagementScene& managementScene) :
ManagementBase(m_sceneName, managementScene){

	

}


ManagementBattle::~ManagementBattle(){
}

void ManagementBattle::PushKeyState(AppController::eGetController pushKey){
	//コントローラー入力処理を記述

}

void ManagementBattle::PushKeyState(){
	

}

void ManagementBattle::Init(){
	m_pBattleCard = std::make_unique<BattleCard>();
	m_pBattleEnemy = std::make_unique<BattleEnemy>();
	m_pBattleMedium = std::make_unique<BattleMedium>();
	m_pBattlePlayer = std::make_unique<BattlePlayer>();
	m_pScnene = std::make_unique<SceneBattle>();

	//スタート画面の初期化処理
	DrawFormatString(0, 10, GetColor(255, 255, 255), "戦闘画面");
	
}

bool ManagementBattle::Render(){
	m_pScnene->Render();

	return true;
}

void ManagementBattle::UpDate(){

	InitPhase();

	
	DrawPhase();
	SelectPhase();
	TurnEnd();

	EnemyPhase();

	BattlePhase();

	EndBattle();
	

}


void ManagementBattle::InitPhase(){
	if (ManagementBattle::m_stateBattle != eBattleState::eInitPhase)return;
	//戦闘の初期化,一度だけ呼ばれる

	MessageBox(NULL, "戦闘開始！", "デバッグ", MB_OK);

	ManagementBattle::m_stateBattle = eBattleState::eDrawPhase;
}


/////////////////////////////////////
//戦闘時のプレイヤーの行動処理
////////////////////////////////////
void ManagementBattle::DrawPhase(){
	if (ManagementBattle::m_stateBattle != eBattleState::eDrawPhase)return;

	//ドローの処理

	ManagementBattle::m_stateBattle = eBattleState::eSelectPhase;
}

void ManagementBattle::SelectPhase(){
	if (ManagementBattle::m_stateBattle != eBattleState::eSelectPhase)return;
	
	//それぞれの選択処理に飛ぶ

	this->SelectCardPhase();
	this->SelectMediumPhase();
	this->SelectEnemyPhase();

	ManagementBattle::m_stateBattle = eBattleState::eTurnEnd;
}

void ManagementBattle::TurnEnd(){

	if (ManagementBattle::m_stateBattle != eBattleState::eTurnEnd)return;

	//ターン終了処理

	ManagementBattle::m_stateBattle = eBattleState::eEnemyPhase;
}

////////////////////////////////////////////
//	戦闘時の敵の処理
///////////////////////////////////////////
void ManagementBattle::EnemyPhase(){
	if (ManagementBattle::m_stateBattle != eBattleState::eEnemyPhase)return;

	//Enemyの思考処理

	ManagementBattle::m_stateBattle = eBattleState::eBattlePhase;
}

//////////////////////////////////
//実際の戦闘処理（ダメージ計算とか）
/////////////////////////////////
void ManagementBattle::BattlePhase(){
	if (ManagementBattle::m_stateBattle != eBattleState::eBattlePhase)return;

	//ダメージ計算とか死亡判定

	ManagementBattle::m_stateBattle = eBattleState::eEndBattle;
}


void ManagementBattle::SelectCardPhase(){
	if (ManagementBattle::m_stateSelect != eSelect::eCardPhase)return;

	//カード選択処理

	ManagementBattle::m_stateSelect = eSelect::eMediumPhase;
}

void ManagementBattle::SelectMediumPhase(){
	if (ManagementBattle::m_stateSelect != eSelect::eMediumPhase)return;
	
	//媒体選択処理

	ManagementBattle::m_stateSelect = eSelect::eEnemyPhase;
}
void ManagementBattle::SelectEnemyPhase(){
	if (ManagementBattle::m_stateSelect != eSelect::eEnemyPhase)return;
	
	//敵選択処理

}



void ManagementBattle::EndBattle(){
	if (ManagementBattle::m_stateBattle != eBattleState::eEndBattle)return;

	

	ManagementBattle::m_stateBattle = eBattleState::eDrawPhase;

	ChangeScene(ManagementScene::ChangeSceneData(
		ManagementStart::m_sceneName, Transition::State::BlackIn, Transition::State::BlackOut));
}


//////////////////////////////////////
//	画像解放処理
/////////////////////////////////////
void ManagementBattle::ImageDelete(){
	m_pBattleEnemy->ImageDelete();
	m_pScnene->ImageDelete();

	m_pBattleEnemy = nullptr;
	m_pScnene = nullptr;

}


