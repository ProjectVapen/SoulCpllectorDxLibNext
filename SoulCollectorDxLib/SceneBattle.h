#pragma once
#include "SceneBase.h"
#include "Include.h"
class SceneBattle :
	public SceneBase
{

	private:
		//‰æ‘œƒnƒ“ƒhƒ‹
		int m_backImage;
	public:
		SceneBattle();
		~SceneBattle();

		void Render()override;
		void ImageDelete()override;
};

