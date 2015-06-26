#pragma once
#include "SceneBase.h"
#include "Include.h"
class SceneStart:
	public SceneBase
{
	private:
		// ‰æ‘œƒnƒ“ƒhƒ‹
		int m_backImage;
	public:
		SceneStart();
		~SceneStart();

		void Render()override;
		void ImageDelete()override;
};

