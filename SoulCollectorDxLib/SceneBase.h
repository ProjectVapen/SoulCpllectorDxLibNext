#pragma once
/*
	SceneBase
	
	�w�i�`��N���X
	���ۃN���X

*/
class SceneBase
{
	public:
		virtual ~SceneBase() = default;

		virtual void Render() = 0;

		virtual void ImageDelete() = 0;
};

