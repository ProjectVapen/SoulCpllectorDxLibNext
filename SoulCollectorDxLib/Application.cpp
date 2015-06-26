#include "Application.h"

const int Application::m_windowWidth = 1280;
const int Application::m_windowHeight = 720;

Application::Application()
{

	m_pAppData		= std::make_unique<AppData>();
	m_pAppManager	= std::make_unique<AppManager>();
	m_pController	= std::make_unique<AppController>();
	m_pWindow = std::make_unique<Window>(1280, 720);
}



Application::~Application()
{
}

void Application::AppMain(){
	
	m_pAppManager->AppUpData();
	
	
}

