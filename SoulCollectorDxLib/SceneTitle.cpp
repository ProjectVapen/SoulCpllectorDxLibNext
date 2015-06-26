#include "SceneTitle.h"
#include "Application.h"


SceneTitle::SceneTitle() 
{
	m_backImage = LoadGraph("Asset/Scenes/Title.png");
}


SceneTitle::~SceneTitle(){

	

}

void SceneTitle::Render(){

	DrawExtendGraph(0, 0,
		Application::m_windowWidth, Application::m_windowHeight, m_backImage, FALSE);
}

void SceneTitle::ImageDelete(){
	DeleteGraph(m_backImage);
}