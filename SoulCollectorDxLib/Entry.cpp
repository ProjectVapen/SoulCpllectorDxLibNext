#include "Include.h"
#include "Application.h"
//	�R���\�[���\���p
#include <io.h>
#include <fcntl.h>

int hConsole = 0;

void CreateConsoleWindow();
void CloseConsoleWindow();


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	Application app;
	

	ChangeWindowMode(TRUE),
	SetGraphMode(Application::m_windowWidth,Application::m_windowHeight, 32);
	SetDrawScreen(DX_SCREEN_BACK);
	

	if (DxLib_Init() == -1)    // �c�w���C�u��������������
	{
		return -1;
	}
	
	//CreateConsoleWindow();
	while (ScreenFlip() == 0 && ProcessMessage() == 0 &&
		ClearDrawScreen() == 0)
	{
		app.AppMain();
	}
	

	DxLib_End();
	CloseConsoleWindow();
	return 0;        // �\�t�g�̏I��
}

void CreateConsoleWindow()
{

	AllocConsole();
	hConsole = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	*stdout = *_fdopen(hConsole, "w");
	setvbuf(stdout, NULL, _IONBF, 0);
}

void CloseConsoleWindow()
{
	_close(hConsole);
}