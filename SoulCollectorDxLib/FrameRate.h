#pragma once
/*

	FrameRate算出クラス
	使用する場合は描画のとこでクラス型変数を作り、
	GetFrameRate関数を呼び出す

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

		int _counterFlg;				//使用する計測関数の判定フラグ
		LARGE_INTEGER _counter;			//クロックカウント数
		double _oneSecoundCounter;		//一秒あたりのクロックカウント数
		LONGLONG _prevCounter;			//以前のクロックカウント数
		DWORD _prevTime;				//以前の時刻（ミリ秒）
	
		std::list<double> _listTimes;	//時間リスト
		UINT _moveAverageNum;			//移動平均計算時のデータ数
		double _commonSumTimes;			//共通部分の合計値

		TCHAR _strFrameRate[20];		//表示用

	public:	
		FrameRate(static const unsigned int smp =10);
		virtual~FrameRate();
		

		//FrameRate（FPS）値の取得
		double GetFrameRate();
		
		//サンプル数の変更
		void SetSampleNum(unsigned int smp);

	protected:
		//現在の差分時刻をミリ単位で取得
		double GetCurDefTime();

		//FrameRate(FPS)を更新
		double UpdataFrameRate(double Def);
};

