#pragma once
/*
	SceneBase
	
	”wŒi•`‰æƒNƒ‰ƒX
	’ŠÛƒNƒ‰ƒX

*/
class SceneBase
{
	public:
		virtual ~SceneBase() = default;

		virtual void Render() = 0;

		virtual void ImageDelete() = 0;
};

