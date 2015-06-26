#pragma once
/*
	�����̃��C�����[�v��



*/
#include "AppManager.h"
#include "AppData.h"
#include "AppController.h"
#include "Window.h"
#include "Include.h"

class Application
{
	private:
		std::unique_ptr<AppManager> m_pAppManager;
		std::unique_ptr<AppData>	m_pAppData;
		std::unique_ptr<AppController>m_pController;
		std::unique_ptr<Window> m_pWindow;

	public:

		Application();
		~Application();

		void AppMain();	//���ۂ̃��C�����֐�

		static const int m_windowWidth;
		static const int m_windowHeight;
};