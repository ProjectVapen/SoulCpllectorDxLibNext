#pragma once
/*
	�퓬�Ǘ��N���X

*/
#include "BattleCard.h"
#include "BattleEnemy.h"
#include "BattleMedium.h"
#include "BattlePlayer.h"
#include "ManagementBase.h"
#include "Include.h"
#include "AppController.h"
class ManagementBattle : public ManagementBase
{
	private:
		
		std::unique_ptr<BattleCard> m_pBattleCard;
		std::unique_ptr<BattleEnemy> m_pBattleEnemy;
		std::unique_ptr<BattleMedium> m_pBattleMedium;
		std::unique_ptr<BattlePlayer> m_pBattlePlayer;
		
		bool m_isSelect;

		//	�퓬�̗���	//
		typedef enum class _EBattleState{
			eInitPhase,

			eDrawPhase,
			eSelectPhase,
			eTurnEnd,
			
			eEnemyPhase,
			
			eBattlePhase,
			
			eEndBattle
		}eBattleState;
		static eBattleState m_stateBattle;

		//	�I�������̗���	//
		typedef enum class _ESelect{

			eCardPhase,
			eMediumPhase,
			eEnemyPhase

		}eSelect;
		static eSelect m_stateSelect;


		void SelectCardPhase();		//�J�[�h�I������
		void SelectMediumPhase();	//�J�[�h������}�̂�I��
		void SelectEnemyPhase();	//�G�I������

		void InitPhase();	//�퓬�̏�����

		void DrawPhase();	//�R�D����J�[�h������
		void SelectPhase();	//�I���������Ăяo���z

		void TurnEnd();		//�^�[���I������

		void EnemyPhase();	//	�G�̎v�l��
		void BattlePhase();	//�퓬�J�n�B�i�_���[�W�v�Z�Ƃ��j

		void EndBattle();

	public:

		ManagementBattle(ManagementScene& managementScene);
		~ManagementBattle();

		/*���͏���*/
		void PushKeyState(AppController::eGetController pushKey);
		void PushKeyState();

		void Init()override;
		void UpDate()override;
		bool Render()override;

		/*	�摜�������	*/
		void ImageDelete()override;


		static const std::string m_sceneName;
		
};

