#pragma once
#include "SceneBase.h"
#include "Include.h"
class SceneStart:
	public SceneBase
{
	private:
		// 画像ハンドル
		int m_backImage;
	public:
		SceneStart();
		~SceneStart();

		void Render()override;
		void ImageDelete()override;
};

