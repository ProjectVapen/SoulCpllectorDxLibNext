#pragma once
/*
	ManagementBase

	�Ǘ����N���X
	���ۃN���X


*/
#include "Include.h"
#include "ManagementScene.h"
#include "SceneBase.h"
class ManagementBase{

	private:

		const std::string m_name;
		ManagementScene& m_managementScene;

	protected:

		//�V�[����؂�ւ���Ƃ��Ɏg�p
		void ChangeScene(const ManagementScene::ChangeSceneData& changeSceneData){
			m_managementScene.ChangeScene(changeSceneData);
		}

		std::unique_ptr<SceneBase> m_pScnene;

	public:
		//�V�[���̖��O�A�V�[���Ǘ��̎��ԎQ��

		ManagementBase(const std::string &name, ManagementScene& Scene) :
			m_name(name),
			m_managementScene(Scene)
		{

		}
		

		virtual ~ManagementBase() = default;

		//������
		virtual void Init() = 0;

		//�X�V
		virtual void UpDate() = 0;

		//�`��
		virtual bool Render() = 0;

		//�摜�̉������
		virtual void ImageDelete() = 0;

		//�V�[�����̎擾
		const std::string Name()const{ return m_name; }

		


};