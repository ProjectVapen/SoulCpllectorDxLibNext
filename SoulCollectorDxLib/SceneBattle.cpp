#include "SceneBattle.h"
#include "Application.h"


SceneBattle::SceneBattle(){

	m_backImage = LoadGraph("Asset/Scenes/Battle.png");
}


SceneBattle::~SceneBattle(){
	DeleteGraph(m_backImage);
}

void SceneBattle::Render(){
	DrawExtendGraph(0, 0,
		Application::m_windowWidth, Application::m_windowHeight, m_backImage, FALSE);

}


void SceneBattle::ImageDelete(){
	DeleteGraph(m_backImage);
}