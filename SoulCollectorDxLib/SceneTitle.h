#pragma once
#include "SceneBase.h"
#include "Include.h"
class SceneTitle:
	public SceneBase
{
	private:
		//‰æ‘œƒnƒ“ƒhƒ‹
		int m_backImage;
	public:
		SceneTitle();
		~SceneTitle();

		void Render()override;
		void ImageDelete()override;
};

