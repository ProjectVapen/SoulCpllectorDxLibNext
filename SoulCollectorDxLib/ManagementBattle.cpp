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
	m_pBattleEnemy->Render();
	
	return true;
}

void ManagementBattle::UpDate(){

	InitPhase();

	if (Render()){
		DrawPhase();
		SelectPhase();
		TurnEnd();

		EnemyPhase();

		BattlePhase();

		EndBattle();
	}

}

void ManagementBattle::InitPhase(){
	if (ManagementBattle::m_stateBattle != eBattleState::eInitPhase)return;
	//�퓬�̏�����,��x�����Ă΂��

	MessageBox(NULL, "�퓬�J�n�I", "�f�o�b�O", MB_OK);

	ManagementBattle::m_stateBattle = eBattleState::eDrawPhase;
}


/////////////////////////////////////
//�퓬���̃v���C���[�̍s������
////////////////////////////////////
void ManagementBattle::DrawPhase(){
	if (ManagementBattle::m_stateBattle != eBattleState::eDrawPhase)return;

	//�h���[�̏���
	MessageBox(NULL, "���̃^�[���h���[�I", "�f�o�b�O", MB_OK);
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
	MessageBox(NULL, "�^�[���G���h�I", "�f�o�b�O", MB_OK);
	ManagementBattle::m_stateBattle = eBattleState::eEnemyPhase;
}

////////////////////////////////////////////
//	�퓬���̓G�̏���
///////////////////////////////////////////
void ManagementBattle::EnemyPhase(){
	if (ManagementBattle::m_stateBattle != eBattleState::eEnemyPhase)return;

	//Enemy�̎v�l����
	MessageBox(NULL, "����Â�����Ȃ�I�i�X���C���j", "�f�o�b�O", MB_OK);
	ManagementBattle::m_stateBattle = eBattleState::eBattlePhase;
}

//////////////////////////////////
//���ۂ̐퓬�����i�_���[�W�v�Z�Ƃ��j
/////////////////////////////////
void ManagementBattle::BattlePhase(){
	if (ManagementBattle::m_stateBattle != eBattleState::eBattlePhase)return;

	//�_���[�W�v�Z�Ƃ����S����
	MessageBox(NULL, "�퓬���I", "�f�o�b�O", MB_OK);
	ManagementBattle::m_stateBattle = eBattleState::eEndBattle;
}


void ManagementBattle::SelectCardPhase(){
	if (ManagementBattle::m_stateSelect != eSelect::eCardPhase)return;

	//�J�[�h�I������
	MessageBox(NULL, "���͂��̃J�[�h��I�Ԃ��I", "�f�o�b�O", MB_OK);
	ManagementBattle::m_stateSelect = eSelect::eMediumPhase;
}

void ManagementBattle::SelectMediumPhase(){
	if (ManagementBattle::m_stateSelect != eSelect::eMediumPhase)return;
	
	//�}�̑I������
	MessageBox(NULL, "�I�񂾃J�[�h�������ɃZ�b�g�I", "�f�o�b�O", MB_OK);
	ManagementBattle::m_stateSelect = eSelect::eEnemyPhase;
}
void ManagementBattle::SelectEnemyPhase(){
	if (ManagementBattle::m_stateSelect != eSelect::eEnemyPhase)return;
	
	//�G�I������
	MessageBox(NULL, "���O�͂������U������񂾁I", "�f�o�b�O", MB_OK);
}



void ManagementBattle::EndBattle(){
	if (ManagementBattle::m_stateBattle != eBattleState::eEndBattle)return;
	MessageBox(NULL, "�퓬�I���I", "�f�o�b�O", MB_OK);
	

	ManagementBattle::m_stateBattle = eBattleState::eDrawPhase;
	ChangeScene(ManagementScene::ChangeSceneData(
		ManagementStart::m_sceneName));
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


