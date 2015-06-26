#pragma once
/*

	FrameRate�Z�o�N���X
	�g�p����ꍇ�͕`��̂Ƃ��ŃN���X�^�ϐ������A
	GetFrameRate�֐����Ăяo��

*/
#pragma comment(lib,"winmm.lib")

#include <windows.h>
#include <mmsystem.h>
#include <list>
#include "DxLib.h"
class FrameRate
{

	private:
		const int _QueryperCounter;
		const int _TimeGetTime;

		int _counterFlg;				//�g�p����v���֐��̔���t���O
		LARGE_INTEGER _counter;			//�N���b�N�J�E���g��
		double _oneSecoundCounter;		//��b������̃N���b�N�J�E���g��
		LONGLONG _prevCounter;			//�ȑO�̃N���b�N�J�E���g��
		DWORD _prevTime;				//�ȑO�̎����i�~���b�j
	
		std::list<double> _listTimes;	//���ԃ��X�g
		UINT _moveAverageNum;			//�ړ����όv�Z���̃f�[�^��
		double _commonSumTimes;			//���ʕ����̍��v�l

		TCHAR _strFrameRate[20];		//�\���p

	public:	
		FrameRate(static const unsigned int smp =10);
		virtual~FrameRate();
		

		//FrameRate�iFPS�j�l�̎擾
		double GetFrameRate();
		
		//�T���v�����̕ύX
		void SetSampleNum(unsigned int smp);

	protected:
		//���݂̍����������~���P�ʂŎ擾
		double GetCurDefTime();

		//FrameRate(FPS)���X�V
		double UpdataFrameRate(double Def);
};

