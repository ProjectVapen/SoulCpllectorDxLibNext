#include "BattleMedium.h"
#include "AppController.h"

BattleMedium::BattleMedium()
{

}

void BattleMedium::m_DataInit(){
	m_target = 0;
	Medium1.m_SetMedium("���f���q", 10, 1000, 150, 130, 180, 0, 0);
	Medium2.m_SetMedium("����̚���", 1, 2, 3, 4, 5, 0, 0);
	Medium3.m_SetMedium("�I�΂ꂽ�̂́h����h�ł����B", 10000, 1000000, 10000000, 100000000, 1, 0, 0);
}

void BattleMedium::m_Skill(){
	//����'sCard����ǂ��ɉ����Z�b�g����Ă��邩�󂯎��
	switch (/*�}�̂��Q�b�g����֐�*/1)
	{
	case m_MEDIUM1:
		Medium1.m_MediumSkl(/*�X�L�����Q�b�g����֐�*/1);
		break;
	case m_MEDIUM2:
		Medium2.m_MediumSkl(/*�X�L�����Q�b�g����֐�*/4);
		break;
	case m_MEDIUM3:
		Medium3.m_MediumSkl(/*�X�L�����Q�b�g����֐�*/3);
		break;
	default:
		break;
	}
}

void BattleMedium::m_Target(){

	//������
	if (CheckHitKey(KEY_INPUT_A)) m_target = 1;
	if (CheckHitKey(KEY_INPUT_B)) m_target = 2;
	if (CheckHitKey(KEY_INPUT_C)) m_target = 3;

	if (CheckHitKey(KEY_INPUT_RETURN)){
		switch (/*�}�̂��Q�b�g����֐�*/1)
		{
		case m_MEDIUM1:
			Medium1.m_MediumTag(m_target);
			break;
		case m_MEDIUM2:
			Medium2.m_MediumTag(m_target);
			break;
		case m_MEDIUM3:
			Medium3.m_MediumTag(m_target);
			break;
		default:
			break;
		}

		/*�J�[�h�I���ɖ߂�*/
	}
}

void BattleMedium::m_Proc(){
	m_Skill();
	m_Target();
}