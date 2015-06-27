#pragma once
/*
	ManagementScene

	全シーン管理クラス
*/



#include "SceneBase.h"
#include "Transition.h"
#include "DataScene.h"
#include "Include.h"

class ManagementBase;

class ManagementScene
{

	public:
		ManagementScene();
		~ManagementScene();

		struct ChangeSceneData{

			ChangeSceneData() = default;
			ChangeSceneData(const std::string& name,
				const Transition::State fadeInState,
				const Transition::State fadeOutState) :
				m_name(name),
				m_fadeInState(fadeInState),
				m_fadeOutState(fadeOutState){}

			std::string m_name;
			Transition::State m_fadeInState;
			Transition::State m_fadeOutState;
		};

		//実際のメインループ
		void Loop();
		

		//登録の削除
		static void Delete(const std::string& name);

		//シーンの切り替え
		void ChangeScene(const ChangeSceneData& changeNextScene);

	private:

		//シーンの登録
		static void Register(std::shared_ptr<ManagementBase> scene);

		//検索して取得
		static std::shared_ptr<ManagementBase> Find(const std::string& name);

		
		void Init();		//初期化
		
		
		void UpDate();		//更新処理

		
		void PrevDelete();	//前の状態を削除

		void FadeOut();		//フェードアウト処理
		void FadeIn();		//フェードイン処理
		//現在の処理状態　
		typedef enum class _EState{

			eInit,
			eUpData,
			ePrevDelete,
			eFadeOut,
			eFadeIn

		}eState;

		static eState m_stateScene;
		static std::shared_ptr<ManagementBase> m_pCurrentManagement;
		static std::shared_ptr<ManagementBase> m_pNextManagement;

		static std::unordered_map<std::string, std::shared_ptr<ManagementBase>> m_pSceneData;
		
		std::unique_ptr<Transition> m_pFadeIn;
		std::unique_ptr<Transition> m_pFadeOut;

		ChangeSceneData m_changeSceneData;
};

