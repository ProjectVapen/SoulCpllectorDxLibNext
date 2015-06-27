#include "ManagementBattle.h"
#include "ManagementTitle.h"
#include "ManagementStart.h"
#include "SceneBattle.h"
#include "Application.h"


const std::string ManagementBattle::m_sceneName = "Battle";

ManagementBattle::eBattleState ManagementBattle::m_stateBattle = eBattleState::eInitPhase;
ManagementBattle::eSelect ManagementBattle::m_stateSelect = eSelect::eCardPhase;


ManagementBattle::ManagementBattle(ManagementScene& managementScene) :
ManagementBase(m_sceneName, managementScene){

	

}


ManagementBattle::~ManagementBattle(){
}

void ManagementBattle::PushKeyState(AppController::eGetController pushKey){
	//�R���g���[���[���͏������L�q

}

void ManagementBattle::PushKeyState(){
	

}

void ManagementBattle::Init(){
	m_pBattleCard = std::make_unique<BattleCard>();
	m_pBattleEnemy = std::make_unique<BattleEnemy>();
	m_pBattleMedium = std::make_unique<BattleMedium>();
	m_pBattlePlayer = std::make_unique<BattlePlayer>();
	m_pScnene = std::make_unique<SceneBattle>();

	//�X�^�[�g��ʂ̏���������
	DrawFormatString(0, 10, GetColor(255, 255, 255), "�퓬���");
	
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
	//�퓬�̏�����,��x�����Ă΂��

	m_pBattleEnemy->Render();

	ManagementBattle::m_stateBattle = eBattleState::eDrawPhase;
}


/////////////////////////////////////
//�퓬���̃v���C���[�̍s������
////////////////////////////////////
void ManagementBattle::DrawPhase(){
	if (ManagementBattle::m_stateBattle != eBattleState::eDrawPhase)return;

	//�h���[�̏���
	
	m_pBattleCard->BattleCardStandbyPhase();
	m_pBattleCard->Render();

	ManagementBattle::m_stateBattle = eBattleState::eSelectPhase;
}


void ManagementBattle::SelectPhase(){
	if (ManagementBattle::m_stateBattle != eBattleState::eSelectPhase)return;
	
	//���ꂼ��̑I�������ɔ��

	this->SelectCardPhase();
	this->SelectMediumPhase();
	this->SelectEnemyPhase();

	ManagementBattle::m_stateBattle = eBattleState::eTurnEnd;
}

void ManagementBattle::TurnEnd(){

	if (ManagementBattle::m_stateBattle != eBattleState::eTurnEnd)return;

	//�^�[���I������

	ManagementBattle::m_stateBattle = eBattleState::eEnemyPhase;
}

////////////////////////////////////////////
//	�퓬���̓G�̏���
///////////////////////////////////////////
void ManagementBattle::EnemyPhase(){
	if (ManagementBattle::m_stateBattle != eBattleState::eEnemyPhase)return;

	//Enemy�̎v�l����

	ManagementBattle::m_stateBattle = eBattleState::eBattlePhase;
}



void ManagementBattle::SelectCardPhase(){
	if (ManagementBattle::m_stateSelect != eSelect::eCardPhase)return;

	//�J�[�h�I������

	/*
	if (m_pBattleCard->BattleCardSelect_C_Phase(&selectdata[0], &selectdata[1])){
	CardCount++;
	std::cout << CardCount << std::endl;
	if (CardCount == 3){
	ManagementBattle::m_stateSelect = eSelect::eMediumPhase;
	}
	}
	*/

	ManagementBattle::m_stateSelect = eSelect::eMediumPhase;
}

void ManagementBattle::SelectMediumPhase(){
	if (ManagementBattle::m_stateSelect != eSelect::eMediumPhase)return;
	
	//�}�̑I������


	/*
	int cnt = 0;

	if (CheckHitKey(KEY_INPUT_RETURN)){

	//�}��[cnt].�f�[�^ = selectdata[0]; (Type)
	//�}��[cnt].�f�[�^ = selectdata[0]; (Kind)

	if (SelectCount == 3){
	ManagementBattle::m_stateSelect = eSelect::eEnemyPhase;
	}
	}


	else if (cnt == 3){
	if (CheckHitKey(KEY_INPUT_RIGHT)){
	cnt = 0;
	//(��ʕ� - �}�̂�x���W) / 2�@����с@(��ʍ��� - (�}�̂�y���W+5)�@�̈ʒu�ɃJ�[�\���\��
	}
	}
	else if (cnt == 0){
	if (CheckHitKey(KEY_INPUT_LEFT)){
	cnt = 3;
	}
	}
	else if (CheckHitKey(KEY_INPUT_RIGHT)){
	cnt++;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)){
	cnt--;
	}
	*/

	ManagementBattle::m_stateSelect = eSelect::eEnemyPhase;
}

void ManagementBattle::SelectEnemyPhase(){
	if (ManagementBattle::m_stateSelect != eSelect::eEnemyPhase)return;
	
	//�G�I������

}

//////////////////////////////////
//���ۂ̐퓬�����i�_���[�W�v�Z�Ƃ��j
/////////////////////////////////
void ManagementBattle::BattlePhase(){
	if (ManagementBattle::m_stateBattle != eBattleState::eBattlePhase)return;

	//�_���[�W�v�Z�Ƃ����S����

	ManagementBattle::m_stateBattle = eBattleState::eEndBattle;
}



void ManagementBattle::EndBattle(){
	if (ManagementBattle::m_stateBattle != eBattleState::eEndBattle)return;
	//�퓬�I������
	

	ManagementBattle::m_stateBattle = eBattleState::eInitPhase;

	ChangeScene(ManagementScene::ChangeSceneData(
		ManagementStart::m_sceneName, Transition::State::BlackIn, Transition::State::BlackOut));
}


//////////////////////////////////////
//	�摜�������
/////////////////////////////////////
void ManagementBattle::ImageDelete(){
	m_pBattleEnemy->ImageDelete();
	m_pScnene->ImageDelete();

	m_pBattleEnemy = nullptr;
	m_pScnene = nullptr;

}


