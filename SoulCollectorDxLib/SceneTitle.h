#pragma once
#include "SceneBase.h"
#include "Include.h"
class SceneTitle:
	public SceneBase
{
	private:
		//�摜�n���h��
		int m_backImage;
	public:
		SceneTitle();
		~SceneTitle();

		void Render()override;
		void ImageDelete()override;
};

