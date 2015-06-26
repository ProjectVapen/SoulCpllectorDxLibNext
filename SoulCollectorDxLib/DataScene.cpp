#include "DataScene.h"


DataScene::DataScene(){

	NowScene(eNULL);
	PrevScene(eNULL);
	NextScene(eTITLE);

}
DataScene::~DataScene(){
}

DataScene::eScene DataScene::PrevScene(){
	return m_ePrevScene;
}
DataScene::eScene DataScene::NowScene(){
	return m_eNowScene;
}
DataScene::eScene DataScene::NextScene(){
	return m_eNextScene;
}

void DataScene::PrevScene(DataScene::eScene prevScene){
	m_ePrevScene = prevScene;
}
void DataScene::NowScene(DataScene::eScene nowScene){
	m_eNowScene = nowScene;
}
void DataScene::NextScene(DataScene::eScene nextScene){
	m_eNextScene = nextScene;
}
