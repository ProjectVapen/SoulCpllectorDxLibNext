#pragma once
#include "Include.h"
#include "DataCard.h"
/***************************************************************************/
//	�܂��ȒP�ɗ����������Ă����ƂˁA
//	DataCard��CSV�ǂݍ��݂��āA���̃f�[�^�� ""�f�[�^�Ƃ��Ă�"" �f�b�L�f�[�^�Ƃ��ĕۑ�����񂾁B
//	���̌�ABattleCard�ŏ�L�̃f�b�L�f�[�^���� "�o�g���p��"�f�b�L�f�[�^�ɓǂݍ��ނ񂾁B
//	�Ȃ�ł���Ȗʓ|�Ȃ��Ƃ��Ă邩���Č����ƁA
//	�f�b�L��ɂȂ�Ƃ��[�A��n����߂��Ă��邶���H�s���g�W�����H�����HJAN�I�H
//	���Ă��ƂŃf�[�^����Ȃ炻������܂��ǂݍ��񂶂Ⴈ�����č��_�B
/***************************************************************************/


class BattleCard
{
private:

	typedef struct _BattleCard
	{
		int m_sId;
		int m_sType;
		int m_sKind;
		std::string m_sName;
		std::string m_sGrHand;
	}SBattleCard;

	typedef enum class _Select
	{
		First,
		Second,
		Third,
		Fourth,
		Fifth,
	}eSelect;

	typedef struct _POS
	{

		int pos_x1;
		int pos_x2;

	}SPOS;

	int GrHand[5];

	SPOS s_pos[5];

	//static eSelect e_select;

	std::unique_ptr<DataCard>m_pDataCard;

	std::vector<SBattleCard>m_vBattleDeckData;
	std::vector<SBattleCard>m_vBattleHandData;

public:
	BattleCard();
	~BattleCard();

	//�f�b�L�Ƃ������������񂾂�ˁB
	void BattleCardSetUp();

	//�h���[�t�F�C�Y�݂����Ȃ��B
	void BattleCardStandbyPhase();

	//�܂��̓J�[�h��I������Ƃ��납��͂��܂�
	int BattleCardSelect_C_Phase(int *type, int *kind);

	//�}�̑I�������B�}�̂������ف[
	int BattleCardSelect_M_Phase(int *type, int *kind);
	//���
	void BattleCardEndPhase();

	//�摜�������邨�܂��Ȃ�
	void ImageDelete();

	//������D���J����
	void Render();
};

