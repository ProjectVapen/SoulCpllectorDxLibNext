#pragma once
#include "SceneBase.h"
#include "Include.h"
class SceneStart:
	public SceneBase
{
	private:
		// �摜�n���h��
		int m_backImage;
	public:
		SceneStart();
		~SceneStart();

		void Render()override;
		void ImageDelete()override;
};

