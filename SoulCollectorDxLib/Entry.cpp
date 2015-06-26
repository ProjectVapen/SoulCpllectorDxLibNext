#include "Include.h"
#include "Application.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	Application app;
	

	ChangeWindowMode(TRUE),
	SetGraphMode(Application::m_windowWidth,Application::m_windowHeight, 32);
	SetDrawScreen(DX_SCREEN_BACK);
	

	if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
	{
		return -1;
	}
	

	while (ScreenFlip() == 0 && ProcessMessage() == 0 &&
		ClearDrawScreen() == 0)
	{
		app.AppMain();
	}
	

	DxLib_End();

	return 0;        // ソフトの終了
}