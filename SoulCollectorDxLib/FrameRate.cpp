#include "FrameRate.h"
#include <stdio.h>
#include <Tchar.h>


FrameRate::FrameRate(static const unsigned int smp):
_QueryperCounter(1),
_TimeGetTime(2)
{
	SetSampleNum(smp);

	if (QueryPerformanceCounter(&_counter) != 0)
	{
		_counterFlg = _QueryperCounter;

		_prevCounter = _counter.QuadPart;				//�������̎����i�N���b�N���̎擾�j

		LARGE_INTEGER oneSecoundCounter;
		QueryPerformanceFrequency(&oneSecoundCounter);	//�P�b������̃N���b�N���̎擾
		_oneSecoundCounter = (double)oneSecoundCounter.QuadPart;

	}
	else
	{
		//�t���O�̐؂�ւ�
		_counterFlg = _TimeGetTime;
		//���x���グ��
		timeBeginPeriod(1);

		//�������̎������擾
		_prevTime = timeGetTime();
	}

	GetFrameRate();
}

FrameRate::~FrameRate()
{

	if (_counterFlg == _TimeGetTime)
	{
		timeEndPeriod(1);	//�^�C�}�[�̐��x��߂�
	}
}

//FrameRate�̎擾
double FrameRate::GetFrameRate(){

	double Def = GetCurDefTime();

	if (Def != 0)
	{
		DrawFormatString(1140, 10, GetColor(255, 255, 0), "FrameRate�F%0.1lf ", Def);
		return UpdataFrameRate(Def);
		
	}
	

	return 0;
}


double FrameRate::GetCurDefTime(){

	if (_counterFlg == _QueryperCounter)
	{
		static double finish;
		QueryPerformanceCounter(&_counter);			//���݂̎������擾	
		LONGLONG DiffCounter = _counter.QuadPart - _prevCounter;
		double ConversionCounter = (double)DiffCounter;

		_prevCounter = _counter.QuadPart;			//���݂̎�����ۑ�7

		finish = ConversionCounter * 1000 / _oneSecoundCounter;
		return finish;
	}

	if (_counterFlg == _TimeGetTime)
	{
		DWORD CurrentTime = timeGetTime();
		DWORD CurrentDef = CurrentTime - _prevTime;

		_prevTime = CurrentTime;

		return CurrentDef;
	}
}

double FrameRate::UpdataFrameRate(double Def){

	_listTimes.pop_front();		//��ԌÂ��f�[�^���폜
		
	_listTimes.push_back(Def);	//�V�����f�[�^�̒ǉ�

	//FrameRate�̎Z�o
	double frameRate;
	double AverageDef = (_commonSumTimes + Def) / _moveAverageNum;

	if (AverageDef != 0)
	{
		frameRate = 10000.0 / AverageDef;
	}

	//���ʉ��Z�����̍X�V
	_commonSumTimes += Def - *_listTimes.begin();

	return frameRate;
}

void FrameRate::SetSampleNum(unsigned int smp){

	_moveAverageNum = smp;						//���ς��v�Z�����
	_listTimes.resize(_moveAverageNum, 0.0);	//���X�g�̏�����

	_commonSumTimes = 0;
}