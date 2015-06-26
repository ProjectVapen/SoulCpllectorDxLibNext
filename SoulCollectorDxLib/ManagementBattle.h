#pragma once
/*
	戦闘管理クラス

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

		//	戦闘の流れ	//
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

		//	選択処理の流れ	//
		typedef enum class _ESelect{

			eCardPhase,
			eMediumPhase,
			eEnemyPhase

		}eSelect;
		static eSelect m_stateSelect;


		void SelectCardPhase();		//カード選択処理
		void SelectMediumPhase();	//カードを入れる媒体を選択
		void SelectEnemyPhase();	//敵選択処理

		void InitPhase();	//戦闘の初期化

		void DrawPhase();	//山札からカードを引く
		void SelectPhase();	//選択処理を呼び出す奴

		void TurnEnd();		//ターン終了処理

		void EnemyPhase();	//	敵の思考部
		void BattlePhase();	//戦闘開始。（ダメージ計算とか）

		void EndBattle();

	public:

		ManagementBattle(ManagementScene& managementScene);
		~ManagementBattle();

		/*入力処理*/
		void PushKeyState(AppController::eGetController pushKey);
		void PushKeyState();

		void Init()override;
		void UpDate()override;
		bool Render()override;

		/*	画像解放処理	*/
		void ImageDelete()override;


		static const std::string m_sceneName;
		
};

