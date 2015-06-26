#pragma once
#include "Include.h"
/*
	DataScene

	シーンの情報を格納
	このデータをManagementSceneに渡して切り替えたりする


*/




class DataScene
{
	public:

		typedef enum _EScene{
			eTITLE,
			eSTART,
			eBATTLE,
			eRESULT,

			eNULL
		}eScene;

		DataScene();
		~DataScene();

		//ゲッター
		eScene NowScene();
		eScene PrevScene();
		eScene NextScene();

		//セッター
		void NowScene(eScene nowScene);
		void PrevScene(eScene prevScene);
		void NextScene(eScene nextScene);


	private:

		eScene m_eNowScene;
		eScene m_ePrevScene;
		eScene m_eNextScene;
};

