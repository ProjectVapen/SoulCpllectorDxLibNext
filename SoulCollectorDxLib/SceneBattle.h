#pragma once
#include "SceneBase.h"
#include "Include.h"
class SceneBattle :
	public SceneBase
{

	private:
		//�摜�n���h��
		int m_backImage;
	public:
		SceneBattle();
		~SceneBattle();

		void Render()override;
		void ImageDelete()override;
};

