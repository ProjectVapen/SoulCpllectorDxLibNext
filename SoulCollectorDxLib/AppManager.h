#pragma once
/*
	�Q�[���̑S�̂̊Ǘ��N���X



*/
#include "ManagementBattle.h"
#include "ManagementScene.h"
#include "ManagementTitle.h"
#include "ManagementStart.h"
#include "Include.h"

class AppManager
{
	private:
		

	public:
		AppManager();
		~AppManager();

		std::unique_ptr<ManagementScene>  m_pManagScene;

		void AppUpData();	//	�V�[����؂�ւ���Ƃ��Ȃ񂩂��炠�������̍X�V����


};

