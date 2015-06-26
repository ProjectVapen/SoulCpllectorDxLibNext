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
			ChangeSceneData(const std::string& name) :
				m_sName(name){}

			std::string m_sName;
			Transition::State m_sFadeInState;
			Transition::State m_sFadeOutState;
		};

		void UpDate();

		//登録の削除
		static void Delete(const std::string& name);

		//シーンの切り替え
		void ChangeScene(const ChangeSceneData& changeNextScene);

	private:

		//シーンの登録
		static void Register(std::shared_ptr<ManagementBase> scene);

		//検索して取得
		static std::shared_ptr<ManagementBase> Find(const std::string& name);

		//初期化
		void Init();
		
		//前の状態を削除
		void PrevDelete();

		typedef enum class _EState{

			eInit,
			eUpData,
			ePrevDelete,
			eFadeOut

		}eState;

		static eState m_stateScene;
		static std::shared_ptr<ManagementBase> m_pCurrentScene;
		static std::shared_ptr<ManagementBase> m_pNextScene;

		static std::unordered_map<std::string, std::shared_ptr<ManagementBase>> m_pSceneData;
		std::unique_ptr<Transition> m_pFadeIn;
		std::unique_ptr<Transition> m_pFadeOut;

		ChangeSceneData m_changeSceneData;
};

