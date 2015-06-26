#pragma once
#include "SceneBase.h"
#include "Include.h"
class SceneResult:
	public SceneBase
{
	public:
		SceneResult();
		~SceneResult();

		void Render()override;
		void ImageDelete()override;
};

