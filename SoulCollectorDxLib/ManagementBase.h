#pragma once
/*
	ManagementBase

	管理基底クラス
	抽象クラス


*/
#include "Include.h"
#include "ManagementScene.h"
#include "SceneBase.h"
class ManagementBase{

	private:

		const std::string m_name;
		ManagementScene& m_managementScene;

	protected:

		//シーンを切り替えるときに使用
		void ChangeScene(const ManagementScene::ChangeSceneData& changeSceneData){
			m_managementScene.ChangeScene(changeSceneData);
		}

		std::unique_ptr<SceneBase> m_pScnene;

	public:
		//シーンの名前、シーン管理の実態参照

		ManagementBase(const std::string &name, ManagementScene& Scene) :
			m_name(name),
			m_managementScene(Scene)
		{

		}
		

		virtual ~ManagementBase() = default;

		//初期化
		virtual void Init() = 0;

		//更新
		virtual void UpDate() = 0;

		//描画
		virtual bool Render() = 0;

		//画像の解放処理
		virtual void ImageDelete() = 0;

		//シーン名の取得
		const std::string Name()const{ return m_name; }

		


};