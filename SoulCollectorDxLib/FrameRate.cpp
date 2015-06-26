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

		_prevCounter = _counter.QuadPart;				//生成時の時刻（クロック数の取得）

		LARGE_INTEGER oneSecoundCounter;
		QueryPerformanceFrequency(&oneSecoundCounter);	//１秒あたりのクロック数の取得
		_oneSecoundCounter = (double)oneSecoundCounter.QuadPart;

	}
	else
	{
		//フラグの切り替え
		_counterFlg = _TimeGetTime;
		//精度を上げる
		timeBeginPeriod(1);

		//生成時の時刻を取得
		_prevTime = timeGetTime();
	}

	GetFrameRate();
}

FrameRate::~FrameRate()
{

	if (_counterFlg == _TimeGetTime)
	{
		timeEndPeriod(1);	//タイマーの精度を戻す
	}
}

//FrameRateの取得
double FrameRate::GetFrameRate(){

	double Def = GetCurDefTime();

	if (Def != 0)
	{
		DrawFormatString(1140, 10, GetColor(255, 255, 0), "FrameRate：%0.1lf ", Def);
		return UpdataFrameRate(Def);
		
	}
	

	return 0;
}


double FrameRate::GetCurDefTime(){

	if (_counterFlg == _QueryperCounter)
	{
		static double finish;
		QueryPerformanceCounter(&_counter);			//現在の時刻を取得	
		LONGLONG DiffCounter = _counter.QuadPart - _prevCounter;
		double ConversionCounter = (double)DiffCounter;

		_prevCounter = _counter.QuadPart;			//現在の時刻を保存7

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

	_listTimes.pop_front();		//一番古いデータを削除
		
	_listTimes.push_back(Def);	//新しいデータの追加

	//FrameRateの算出
	double frameRate;
	double AverageDef = (_commonSumTimes + Def) / _moveAverageNum;

	if (AverageDef != 0)
	{
		frameRate = 10000.0 / AverageDef;
	}

	//共通加算部分の更新
	_commonSumTimes += Def - *_listTimes.begin();

	return frameRate;
}

void FrameRate::SetSampleNum(unsigned int smp){

	_moveAverageNum = smp;						//平均を計算する個数
	_listTimes.resize(_moveAverageNum, 0.0);	//リストの初期化

	_commonSumTimes = 0;
}