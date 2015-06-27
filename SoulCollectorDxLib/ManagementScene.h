#pragma once
/*
	ManagementScene

	�S�V�[���Ǘ��N���X
*/



#include "SceneBase.h"
#include "Transition.h"
#include "DataScene.h"
#include "Include.h"

class ManagementBase;

class ManagementScene
{

	public:
		ManagementScene();
		~ManagementScene();

		struct ChangeSceneData{

			ChangeSceneData() = default;
			ChangeSceneData(const std::string& name,
				const Transition::State fadeInState,
				const Transition::State fadeOutState) :
				m_name(name),
				m_fadeInState(fadeInState),
				m_fadeOutState(fadeOutState){}

			std::string m_name;
			Transition::State m_fadeInState;
			Transition::State m_fadeOutState;
		};

		//���ۂ̃��C�����[�v
		void Loop();
		

		//�o�^�̍폜
		static void Delete(const std::string& name);

		//�V�[���̐؂�ւ�
		void ChangeScene(const ChangeSceneData& changeNextScene);

	private:

		//�V�[���̓o�^
		static void Register(std::shared_ptr<ManagementBase> scene);

		//�������Ď擾
		static std::shared_ptr<ManagementBase> Find(const std::string& name);

		
		void Init();		//������
		
		
		void UpDate();		//�X�V����

		
		void PrevDelete();	//�O�̏�Ԃ��폜

		void FadeOut();		//�t�F�[�h�A�E�g����
		void FadeIn();		//�t�F�[�h�C������
		//���݂̏�����ԁ@
		typedef enum class _EState{

			eInit,
			eUpData,
			ePrevDelete,
			eFadeOut,
			eFadeIn

		}eState;

		static eState m_stateScene;
		static std::shared_ptr<ManagementBase> m_pCurrentManagement;
		static std::shared_ptr<ManagementBase> m_pNextManagement;

		static std::unordered_map<std::string, std::shared_ptr<ManagementBase>> m_pSceneData;
		
		std::unique_ptr<Transition> m_pFadeIn;
		std::unique_ptr<Transition> m_pFadeOut;

		ChangeSceneData m_changeSceneData;
};

