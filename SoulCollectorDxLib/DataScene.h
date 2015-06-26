#pragma once
#include "Include.h"
/*
	DataScene

	�V�[���̏����i�[
	���̃f�[�^��ManagementScene�ɓn���Đ؂�ւ����肷��


*/




class DataScene
{
	public:

		typedef enum _EScene{
			eTITLE,
			eSTART,
			eBATTLE,
			eRESULT,

			eNULL
		}eScene;

		DataScene();
		~DataScene();

		//�Q�b�^�[
		eScene NowScene();
		eScene PrevScene();
		eScene NextScene();

		//�Z�b�^�[
		void NowScene(eScene nowScene);
		void PrevScene(eScene prevScene);
		void NextScene(eScene nextScene);


	private:

		eScene m_eNowScene;
		eScene m_ePrevScene;
		eScene m_eNextScene;
};

