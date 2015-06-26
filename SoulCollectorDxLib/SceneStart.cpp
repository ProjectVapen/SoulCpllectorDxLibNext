#include "SceneStart.h"
#include "Application.h"

SceneStart::SceneStart(){
	m_backImage = LoadGraph("Asset/Scenes/Start.png");
}


SceneStart::~SceneStart(){
}

void SceneStart::Render(){
	DrawExtendGraph(0, 0,
		Application::m_windowWidth, Application::m_windowHeight, m_backImage, FALSE);
}

void SceneStart::ImageDelete(){
	DeleteGraph(m_backImage);
}
